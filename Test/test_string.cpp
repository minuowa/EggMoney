#include "stdafx.h"
#include "test_string.h"

#include <codecvt>
#include <xlocbuf>
const std::wstring s2ws ( const std::string& s )
{
    std::locale old_loc = std::locale::global ( std::locale ( "" ) );

    const char* src_str = s.c_str();

    const size_t buffer_size = s.size() + 1;

    wchar_t* dst_wstr = new wchar_t[buffer_size];

    wmemset ( dst_wstr, 0, buffer_size );
    size_t wsize = 0;
    mbstowcs_s ( &wsize, dst_wstr, buffer_size, src_str, buffer_size );

    std::wstring result = dst_wstr;

    delete []dst_wstr;

    std::locale::global ( old_loc );

    return result;

}

std::string narrow ( const std::wstring& wstr, char rep = '_' )
{
    std::string str ( wstr.size(), 0 );
    //std::locale & oldLocal = std::locale::locale ( std::locale ( "chs" ) );
    std::locale & oldLocal = std::locale::locale ();
    std::use_facet<std::ctype<wchar_t> > ( oldLocal ).narrow
    ( &wstr[0], &wstr[0] + wstr.size(), rep, &str[0] );
    return str;
}
test_string::test_string ( void )
{
    {
        const char* str = "1234中国的人";
        static const size_t bufferSize = 1024;
        wchar_t wBuffer[bufferSize];

    }

    {
        std::wstring wstr = L"123,我是谁？我爱钓鱼岛！";
        std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
        std::wstring_convert<std::codecvt_utf16 <char>> convw;

        std::string narrowStr = conv.to_bytes ( wstr );
        {
            std::ofstream ofs ( "c:\\test.txt" );
            ofs << narrowStr;
        }
        uString u8str ( Encoding_UTF8 );
        u8str.set ( narrowStr.c_str(), Encoding_UTF8 );
        std::wstring wstr2 = u8str.unicode().c_strw();//u8->ucs2
        std::string ansistr = u8str.ansi().c_str();//ucs2->ansi
        std::string u8str2 = u8str.utf8().c_str();//ansi->u8
		std::string ansistr2=u8str.ansi().c_str();//u8->ansi
		std::wstring wstr3 = u8str.unicode().c_strw();//ansi->ucs2
		std::string u8str3 = u8str.utf8().c_str();//ucs2->u8
		u8str.setEncoding(Encoding_Unicode);
		u8str.setEncoding(Encoding_ANSI);
		u8str.setEncoding(Encoding_Unicode);
	}

    //std::string wistr = convw.to_bytes ( narrowStr );
    {
		uString str;
		str.append("1中国人");
		str.append(L"2中国人3");
		str.append(5,'4');
		str.append(5,L'人');
		uString str2=str+L"123中国人789";
		str2.format("123中%d国%s人",500,"123中国人");
	}
	{
		uString str;
		str.append("1中国人");
		str.append(L"2中国人3");
		str.append(5,'4');
		str.append(5,L'人');
		uString str2=str+L"123中国人789";
		str2.format("123中%d国%s人",500,"123中国人");
	}
    //
    //setlocale(LC_ALL,"zh_CN.GB2312");
    //setlocale( LC_ALL, "" );
    //= std::locale(std::locale::locale("chs"),"",LC_CTYPE);
    //std::wstring wsss = s2ws ( str );
    //uString ustr = "中国人123";
    //std::wstring wsss = ustr.unicode();
    //std::codecvt?
    //std::codecvt_utf8
}


test_string::~test_string ( void )
{
}
