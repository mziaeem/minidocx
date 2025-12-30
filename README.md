
<div align="center">
  <img src="./assets/logo.png" width="100px">
  <h1>minidocx</h1>
  <p>C++ library for manipulating Microsoft Word Document</p>
</div>

## Note
This is a fork of minidocx that some BiDi and Rtl capabilities added to it. 
It is working, but still is a work in progress. 


## About

minidocx is a modern, free, open-source, cross-platform, light-weight, and user-friendly C++20 library for manipulating Microsoft Word Document (.docx file) as described in [ECMA 376 5th edition](https://www.ecma-international.org/publications-and-standards/standards/ecma-376) or [ISO/IEC 29500-1:2016](https://www.iso.org/standard/71691.html) without installing MS Office or WPS Office.

## Features

- Section
- Paragraph
- Rich text
- Table
- Picture
- Style
- List
- Rtl Support


## Example

Here's an example of how to use minidocx to create a .docx file.

```cpp
#include "minidocx/minidocx.hpp"
#include <iostream>

int main()
{
  using namespace md;
  try {
    Document doc;
    SectionPointer sect = doc.addSection();

    ParagraphPointer para = sect->addParagraph();
    para->prop_.align_ = Alignment::Centered;
    para->prop_.rtl_ = true; 

    RichTextPointer rich = para->addRichText("سلام به دنیا یعنی Hello world");
    rich->prop_.fontSize_ = 32;
    rich->prop_.direction_ = RichTextProperties::Direction::Rtl; 
    rich->prop_.color_ = "FF0000";

    doc.saveAs("a.docx");
  }
  catch (const Exception& ex) {
    std::cerr << ex.what() << std::endl;
  }
  return 0;
}
```

## Building

To build minidocx lib you'll need a C++20 compiler and CMake 3.28.

```bash
git clone git@github.com:mziaeem/minidocx.git
cd minidocx

# Windows
cmake --preset x64-win-msbuild-v143
cmake --build --preset x64-win-msbuild-v143-debug
./out/x64-win-msbuild-v143/bin/exe/Debug/myapp.exe

# Linux
cmake --preset x64-linux-ninja-gcc
cmake --build --preset x64-linux-ninja-gcc-debug
./out/x64-linux-ninja-gcc/bin/exe/myapp
```

A static library is built by default. If you want to use a shared build of minidocx, set the `BUILD_SHARED` CMake option to `true`.

## Documentation

- [User Guide](./guide.md)

## Donation
If you want to donate me, feel free to send me through crypto
tron:TGLSMZ7c8CN81kb8r75nY7sEy8xRvTGKah

If you benefit from this project, please consider donating to help me sustain my projects actively and make more of my ideas come true.
## License

minidocx is released to the public for free under the terms of the MIT License. See [LICENSE](./LICENSE) for the full text of the license. [LICENSE](./LICENSE) should be distributed alongside any assemblies that use minidocx in source or compiled form.
