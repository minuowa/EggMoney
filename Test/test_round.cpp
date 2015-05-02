#include "stdafx.h"
#include "test_round.h"


test_round::test_round ( void )
{
    test();
}


test_round::~test_round ( void )
{
}

void test_round::test()
{
    {
        double d = 15.0;
        int id = dRound ( d );
        assert ( id == 15 );
        d = 15.2;
        id = dRound ( 15.2 );
        assert ( id == 15 );
        d = 15.8;
        id = dRound ( d );
        assert ( id == 16 );
        d = 15.5;
        id = dRound ( d );
        assert ( id = 16 );
    }
    {
        double d = 15.0;
        int id = dRound ( d, 5 );
        assert ( id == 15 );
        d = 15.2;
        id = dRound ( 15.2, 5 );
        assert ( id == 15 );
        d = 15.8;
        id = dRound ( d, 5 );
        assert ( id == 15 );
        d = 15.5;
        id = dRound ( d, 5 );
        assert ( id == 15 );

        d = 17;
        id = dRound ( d , 5 );
        assert ( id == 15 );

        d = 18;
        id = dRound ( d, 5 );
        assert ( id == 20 );

        d = 19;
        id = dRound ( d, 5 );
        assert ( id == 20 );
    }
}
