
#include "minidocx/minidocx.hpp"
#include "minidocx/word/main/properties/base.hpp"
#include <iostream>


int main()
{
  using namespace md;
  try
  {
    Document doc;
    SectionPointer sect = doc.addSection();

    RichTextProperties::Font nazanin;
    nazanin.cs_ = "B Titr";
    nazanin.hAnsi_ = "B Titr";
    nazanin.ascii_ = "B Titr";

    ParagraphStyle paraStyle;
    paraStyle.name_ = "My Heading 1";
    paraStyle.outlineLevel_ = ParagraphProperties::OutlineLevel::Level1;
    paraStyle.fontSize_ = 32;
    paraStyle.color_ = "FF0000";

    doc.addParagraphStyle(paraStyle);

    ParagraphStyle paraStyle2;
    paraStyle2.name_ = "My Heading 2";
    paraStyle2.outlineLevel_ = ParagraphProperties::OutlineLevel::Level2;
    paraStyle2.fontSize_ = 28;
    paraStyle2.color_ = "0000FF";
    paraStyle2.bidi_ = true; 
    
    doc.addParagraphStyle(paraStyle2);

    ParagraphPointer para = sect->addParagraph();
    para->prop_.bidi_ = true; 
    RichTextPointer rich1 = para->addRichText("عنوانMain اصلی");
    rich1->prop_.font_ = nazanin;
    para->prop_.style_ = "My Heading 1";

    ParagraphPointer para2 = sect->addParagraph();
    RichTextPointer rpt = para2->addRichText("this: این عنوان خوب set شده است. امیدوارم fail نشود.");
    rpt->prop_.direction_ = RichTextProperties::Direction::Rtl;
    para2->prop_.style_ = "My Heading 2";


    doc.saveAs("style.docx");
  }
  catch (const Exception& ex)
  {
    std::cerr << ex.what() << std::endl;
  }
  return 0;
}
