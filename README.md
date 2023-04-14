# 🖼️ image-editor — BMP Image Scaling in C++

A lightweight C++ tool for scaling BMP images. It decodes an uncompressed BMP file, enlarges it by an integer factor and writes the result as a new BMP, without any third-party libraries.

## 📖 How it works

The program is split into small, replaceable parts:

- **`ImageDecoder` / `ImageEncoder`** — abstract interfaces for reading an image row by row and writing it back. New formats can be added by implementing these two classes.
- **`BmpDecoder`** — reads the BMP header, checks the signature and colour depth and returns pixel rows, skipping the row padding.
- **`BmpEncoder`** — builds a new header with the updated size and writes rows with correct 4-byte padding.
- **`ImageScaler`** — scales the image with **nearest-neighbour interpolation**: each pixel is repeated `factor` times horizontally and each row `factor` times vertically.
- **`BmpHeader`, `MetaData`, `Pixel`** — packed header structures and the in-memory pixel representation.

The image is processed as a stream, one row at a time, so even large files never have to be fully loaded into memory.

Supported input: uncompressed BMP with 24 or 32 bits per pixel.

## 🚀 Build and run

```bash
g++ -std=c++17 -O2 -o image_scaler src/*.cpp
./image_scaler data/input.bmp output.bmp 3
```

Arguments: `<input.bmp> <output.bmp> <scale_factor>`, where the scale factor is a positive integer.

## 🧪 Example (scale = 3)

| Input (124×124) | Output (372×372) |
|-----------------|------------------|
| ![input](data/input.bmp) | ![output](data/output.bmp) |

## 🗂 Project structure

```
src/    decoder, encoder, scaler and BMP structures
data/   sample input and output images
```

## 🛠️ Tech stack

C++17 · STL · binary file I/O · no external dependencies
