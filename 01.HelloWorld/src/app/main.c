#include <stdio.h>

int main()
{
    for ( int i = 0; i < 18; i++ )
    {
        for( int j = 0; j < 24; j++ )
        {
            if( (i == 9) && ( j == 9 ) )
            {
                printf("HelloWorld ");
                j+=6;
            }
            
            printf("# ");
        }

        printf("\n");
    }

    return 0;
}