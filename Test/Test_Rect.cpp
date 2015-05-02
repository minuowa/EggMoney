#include "stdafx.h"
#include "Test_Rect.h"


Test_Rect::Test_Rect ( void )
{
    test();
}


Test_Rect::~Test_Rect ( void )
{
}

void Test_Rect::test()
{
	//算法没问题
    {
		long x = 0, y = 0, w = 1000, h = 1000;
		CXRect rc ( x, y, w, h );
		double param = 2;
		CXPoint2 pt ( 20, 20 );
		rc.scale ( param, pt.mX, pt.mY );
		rc.scale ( 1.0 / param, pt.mX, pt.mY );
		CXASSERT ( rc.mX == x && rc.mY == y && rc.mW == w && rc.mH == h );
    }
    {
        long x = 0, y = 0, w = 1024, h = 768;
        CXRect rc ( x, y, w, h );
        double param = 1.01;
        CXPoint2 pt ( 20, 20 );
        rc.scale ( param, pt.mX, pt.mY );
        rc.scale ( 1.0 / param, pt.mX, pt.mY );
		//增量缩放会丢失精度。。。
		CXASSERT ( rc.mX == x && rc.mY == y && rc.mW != w && rc.mH != h );
    }
}
