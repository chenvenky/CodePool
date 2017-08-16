    
    // gcd and extend_gcd 
    /***********************
        input:  two integers 
        return: the greatest common divisor of the two integers
        you also can get lowest common multiple of the two integers
        by： lcm*gcd = a*b 
        *************************/

        int gcd(int a, int b)
        {
            return b ? gcd(b, a%b) : a;
        }

    /*****************************
        The EXtended EEuclidean algorithm

        solve problems such as: ax + by = c
        a, b, c are three integers
        
        input : a, b, c
        get: x, y 
        ******************************/

        extend_gcd(int a, int b, int & d, int & x, int & y)
        {
            if(!b) { d = a; x = 1; y = 0; }
            else { extend_gcd(b, a%b, d, y, x); y -= x*(a/b); }
        }

        int tmp = c/gcd(x, y);
        x = x*tmp;
        y = y*tmp;
