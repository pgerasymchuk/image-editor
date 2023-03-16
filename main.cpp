#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BmpDecoder.h"
#include "BmpEncoder.h"
#include "ImageScaler.h"

using namespace std;

int main(int argc, char** argv) {
    try {
        if (argc != 4) {
            cerr << "Usage: " << argv[0] << " <input_path> <output_path> <scale_factor>" << endl;
            return 1;
        }

        string inputPath = argv[1];
        string outputPath = argv[2];
        int scaleFactor = stoi(argv[3]);

        if (scaleFactor <= 0) {
            cerr << "Scale factor must be a positive integer." << endl;
            return 1;
        }

        ifstream inFile(inputPath, ios::binary);
        if (!inFile) {
            cerr << "Error: Cannot open input file: " << inputPath << endl;
            return 1;
        }
        inFile.close();

        ofstream outFile(outputPath, ios::binary);
        if (!outFile) {
            cerr << "Error: Cannot open or create output file: " << outputPath << endl;
            return 1;
        }
        outFile.close();

        ImageDecoder* decoder = new BmpDecoder(inputPath);
        ImageEncoder* encoder = new BmpEncoder(outputPath);
        ImageScaler scaler(decoder, encoder);
        scaler.scale(scaleFactor);

        delete decoder;
        delete encoder;
    }
    catch (exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return 1;
    }
}
