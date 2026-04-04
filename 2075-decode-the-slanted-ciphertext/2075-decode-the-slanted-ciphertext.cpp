class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows<=1)
        return encodedText;
        string decode="";
        int n=encodedText.length();
        int m=n/rows;
        for(int i=0;i<m;i++)
        {  
           for(int j=0;j<rows;j++)
           {
            if(i+j+(m*j)<rows*m)
            {char ch=encodedText[i+j+(m*j)];
            decode+=ch;}
           }
        }
        //for trailing space
        while(!decode.empty() && decode.back()==' ')
        decode.pop_back();

        return decode;
    }
};