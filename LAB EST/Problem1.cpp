class Solution {
  public:
    vector<int> gcd(int a, int b) {
        int x0 = 1, y0 = 0;
        int x1 = 0, y1 = 1;
        
        while (b != 0) {
            int q = a / b;
            int r = a % b;
            
            int x2 = x0 - q * x1;
            int y2 = y0 - q * y1;
            
            a = b;
            b = r;
            x0 = x1; y0 = y1;
            x1 = x2; y1 = y2;
        }
        
        return {a, x0, y0};
    }
};
