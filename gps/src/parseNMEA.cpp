
#include "parseNMEA.h"
#include "types.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <stdexcept>

using namespace std;
namespace GPS{

/*  Determine whether the parameter is a valid NMEA sentence, including verifying
   *  the checksum.
   *
   *  A NMEA sentence consists of:
   *    - the prefix "$GP";
   *    - followed by a three-character identifier for the sentence format;
   *    - followed by a sequence of comma-separated fields;
   *    - followed by a '*' character;
   *    - followed by a two-character hexadecimal checksum.
   *	- $GPGGA,091138.000,5320.4819,N,00136.3714,W,1,0,,395.0,M,,M,,*46
   *  For a NMEA sentence to be valid, the checksum value should equal the byte-wise XOR reduction
   *  of the characters codes of all characters between the '$' and the '*'.
   */
bool isValidSentence(const string &input){
    bool hasPrefix, hasIdentifier, hasCSValues, hasEndDelimiter, hasChecksum;
    //Check for empty strings
    if (input.length()==0){
        return false;
    }

    //Pull the first 3 characters into a char array, check for correct prefix. Has absolute position
    char charArr[5];
    size_t length =input.copy(charArr,3,0);
    string prefix(charArr);
    if (prefix=="$GP"){
        hasPrefix=true;
    }
    else{
        return false;
    }
    //Pull the identifier for sentence format, has absolute position so will always work
    length=input.copy(charArr,3,3);
    string identifier(charArr);
    if (identifier.length()==3){
        hasIdentifier=true;
    }
    else{
        return false;
    }
    //Check for the start of the CSVs, will have absolute position
    string csValue=input.substr(6,1);
    if(csValue==","){
        hasCSValues=true;
    }
    else{
        return false;
    }
    //Finds the last instance of the * character, in case of wildcards in data. if the position is greater than the minimum length carry on
    char key ='*';
    size_t pos=input.rfind(key);
    if (pos>6){
        hasEndDelimiter=true;
    }
    else{
        return false;
    }
    //Get the checksum digits, will always be after the * so use that position as reference
    string check;
    check=input.substr(pos+1);
    if (check.length()!=2){
        hasChecksum=false;
    }
    //single out the string
    string checkSum=input.substr(input.find('$'),input.find('*'));
    int total=checkSum[0];
    //Sum up the total via XOR
    for(int i=0;i<checkSum.length();i++){
        total=total^int(checkSum[i]);
    }
    //Convert the check sum to decimal
    stringstream ss;
    int totalCheck;
    ss<<hex<<check;
    ss>>totalCheck;
    //Compare the checksum total with calculated total
    if (totalCheck==total){
        hasChecksum=true;
    }
    else{
        hasChecksum=false;
    }
    //Check for all conditions
    if (hasPrefix && hasIdentifier && hasCSValues && hasEndDelimiter && hasChecksum == true){
        return true;
    }
    else {
        return false;
    }

}


/*  Pre-condition: the parameter is a valid NMEA sentence.
*  Decomposes the sentence into the sentence type and the individual fields.
*  The checksum is discarded.
*/
NMEAPair decomposeSentence(const string &nmeaSentence){
    NMEAPair output;
    output.first=nmeaSentence.substr(1,5);
    string values=nmeaSentence.substr(nmeaSentence.find_first_of(',')+1,nmeaSentence.find('*')-7);
    vector<string> valuesVector;
    stringstream ss;
    ss<<values;
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        valuesVector.push_back(substring);
    }
    output.second=valuesVector;
    return output;
}


/*  Computes a Position from a NMEAPair.
*  For ill-formed or unsupported sentence types, throws a std::invalid_argument exception.
*/
Position extractPosition(const NMEAPair &input){
    vector<string> sentence=input.second;
    if(input.first=="GPGLL"){
        string latStr=sentence[0];
        string lonStr=sentence[2];
        char northing=sentence[1][0];
		char easting=sentence[3][0];
		if (northing=='N' || northing=='S')
		{
			if (easting=='E'|| easting=='W'){
				Position output (latStr,northing,lonStr,easting,"0");
                return output;
			}
			else{
            throw invalid_argument("Invalid Argument");
			}
		}
		else{
            throw invalid_argument("Invalid Argument");
        }		
    }
    else if(input.first=="GPRMC"){
        string latStr=sentence[2];
		string lonStr=sentence[4];
		char northing=sentence[3][0];
		char easting=sentence[5][0];
		if (northing=='N' || northing=='S')
		{
			if (easting=='E'|| easting=='W'){
				Position output (latStr,northing,lonStr,easting,"0");
                return output;
			}
			else{
            throw invalid_argument("Invalid Argument");
			}
		}
		else{
            throw invalid_argument("Invalid Argument");
        }        

    }
    else if (input.first=="GPGGA"){
        string latStr=sentence[1];
		string lonStr=sentence[3];
		char northing=sentence[2][0];
		char easting=sentence[4][0];
		if (northing=='N' || northing=='S')
		{
			if (easting=='E'|| easting=='W'){
				Position output (latStr,northing,lonStr,easting,sentence[8]);
                return output;
			}
			else{
            throw invalid_argument("Invalid Argument");
			}
		}
		else{
            throw invalid_argument("Invalid Argument");
        }
    }
    else{
        throw invalid_argument("Invalid Argument");
    }
}

/*  Pre-condition: The parameter is the filepath of a file containing NMEA sentences
*  (one per line).
*  Reads the file, and returns a vector of Positions extracted from the sentences.
*  Blank lines or invalid sentences are ignored.
*/
vector<Position> routeFromNMEALog(const string &filepath){
    vector<Position> output;
    string currentLine;
    ifstream inputFile;
    inputFile.open(filepath);
    while(getline(inputFile,currentLine)){
        if (isValidSentence(currentLine)){
            output.push_back(extractPosition(decomposeSentence(currentLine)));
        }
    }
	inputFile.close();
    return output;
}
}
