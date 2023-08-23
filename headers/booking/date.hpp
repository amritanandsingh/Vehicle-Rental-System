#ifndef DATE_HPP
#define DATE_HPP
class Date{
            public:
                int dd;
                int mm;
                int yyyy;
                Date(int a,int b,int c)
                {
                    dd= a;
                    mm= b;
                    yyyy = c;
                }
        };
#endif