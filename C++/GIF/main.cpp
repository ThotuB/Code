#include <iostream>
#include <fstream>
#include <string>

#define byte char

using namespace std;

class Header {
public:
    byte header[7];

    string signature;
    string version;

    Header(){}

    Header(byte buffer[6]){
        signature = string(buffer, 3);
        version = string(buffer+3, 3);
    }

    void print(){
        cout << "Header:\n";
        cout << "signature: " << signature << "\n";
        cout << "version: " << version << "\n";
    }
};

class LogicalScreenDesc {
private:
    unsigned bytes_to_uint(byte buffer[2]){
        return buffer[0] + 16 * buffer[1];
    }

    unsigned get_bits(byte b, unsigned size, unsigned bitStart){
        return ( b >> bitStart ) & ~( ~0 << size );
    }

public:
    unsigned width;
    unsigned height;
    // Packed Field
    unsigned colTabFlag;
    unsigned colRes;
    unsigned sortFlag;
    unsigned colTabSize;

    unsigned bgColIndex;
    unsigned aspectRatio;

    LogicalScreenDesc(){}

    LogicalScreenDesc(byte buffer[7]){
        width = bytes_to_uint(buffer);
        height = bytes_to_uint(buffer+2);

        colTabFlag = get_bits(buffer[4], 1, 7);
        colRes = get_bits(buffer[4], 3, 4);
        sortFlag = get_bits(buffer[4], 1, 3);
        colTabSize = get_bits(buffer[4], 3, 0);
        
        bgColIndex = buffer[5];
        aspectRatio = buffer[6];
    }

    void print(){
        cout << "Logical Screen Descriptor:\n";
        cout << "width: " << width << '\n';
        cout << "height: " << height << '\n';
        cout << "global ct flag: " << colTabFlag << '\n';
        cout << "color res: " << colRes << '\n';
        cout << "sort flag: " << sortFlag << '\n';
        cout << "global ct size: " << colTabSize << '\n';
        cout << "background color i: " << bgColIndex << '\n';
        cout << "aspect ratio: " << aspectRatio << '\n';
    }
};

class GlobalColorTable {
public:
    unsigned size;
    unsigned **colTable;

    GlobalColorTable(){}

    GlobalColorTable(byte *buffer, unsigned _size){
        size = _size;
        colTable = new unsigned*[size];
        
        for (unsigned i = 0 ; i < size ; i++){
            colTable[i] = new unsigned[3];

            colTable[i][0] = (uint8_t)buffer[3*i];
            colTable[i][1] = (uint8_t)buffer[3*i+1];
            colTable[i][2] = (uint8_t)buffer[3*i+2];
        }
    }

    void print(){
        cout << "Global Color Table:\n";
        for (unsigned i = 0 ; i < size ; i++){
            cout << "#" << i << '\t';
            cout << colTable[i][0] << '\t';
            cout << colTable[i][1] << '\t';
            cout << colTable[i][2] << '\n';
        }
    }
};

class GIF {
public:
    Header gifHeader;
    LogicalScreenDesc gifLSD;
    GlobalColorTable gifGCT;

    GIF(ifstream &gifStream){
        byte *buffer;

        // HEADER
        buffer = new byte[6];
        gifStream.read(buffer, 6);
        gifHeader = Header(buffer);

        // LOGICAL SCREEN DESCRIPTOR
        buffer = new byte[7];
        gifStream.read(buffer, 7);
            
        gifLSD = LogicalScreenDesc(buffer);
        
        // GLOBAL COLOR TABLE
        if ( gifLSD.colTabFlag ){
            unsigned size = 1 << ( gifLSD.colTabSize + 1 );

            buffer = new byte[size*3];
            gifStream.read(buffer, size*3);

            gifGCT = GlobalColorTable(buffer, size);
        }
    }

    void print(){
        gifHeader.print(); cout << '\n';
        gifLSD.print(); cout << '\n';
        gifGCT.print(); cout << '\n';
    }
};

int main(){
    ifstream gifFile("example.gif", ios::binary);
    GIF myGIF(gifFile);

    myGIF.print();
}