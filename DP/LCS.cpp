#include <bits/stdc++.h>
using namespace std;

class LCS
{

    string s1, s2; /* strings to be compared to find 
    longest common subsequence */
	
	int len1, len2;
	
    int lcsSize; // size of LCS

    string lcs; // stores LCS

    int **dp; // dp array for calculating lcs

	void calcLCS()
    {     
        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
public:

    LCS(string i1, string i2)
    {
        this->s1 = i1;
        this->s2 = i2;

        len1 = s1.size();
        len2 = s2.size();
		
		lcsSize = 0;
		lcs = "";
		
		dp = new int* [len1 + 1];
		for(int i=0; i<=len1; i++)
			dp[i] = new int [len2 + 1];
    }
     
    int getSizeLCS()
    {
        if(lcsSize == 0)
            calcLCS();
		
		lcsSize = dp[len1][len2];
		
        return lcsSize;
    }

    string getLCS()
    {
    
        if(lcs.size() != 0)
        	return lcs;
        	
        if(lcsSize == 0)
        	calcLCS();
            
        int i = len1;
        int j = len2;

        while(lcs.size() != dp[len1][len2])
        {
            if(dp[i][j] == dp[i-1][j])
                i -= 1;
            else if(dp[i][j] == dp[i][j-1])
                j -= 1;
            else
            {
                lcs += (s1[i-1]);
                i -= 1;
                j -= 1;
            }
        }
		
		reverse(lcs.begin(), lcs.end());
		
        return lcs;
    }

    void printDPmatrix()
    {  
        for(int i=0; i<=len1; i++)
        {
        	for(int j=0; j<=len2; j++)
        	{
        		cout << dp[i][j] << " ";
        	}
        	cout << endl;
        }
    }
    
    ~LCS()
    {
    	for(int i=0; i<=len1; i++)
    		delete [] dp[i];
    	delete [] dp;
    }

};

int main()
{
    cout << "Enter string 1:\n";
    string input1;
    cin >> input1;
    
    cout << "Enter string 2:\n";
    string input2;
    cin >> input2;
    
    cout << "\nThe strings entered are:\n";
    cout << input1 << endl;
    cout << input2 << endl;
    cout << endl;

    LCS a(input1, input2);

    cout << "The length of Longest Common Subsequence:\n";
    cout << a.getSizeLCS() << endl;
   	cout << endl;

    cout << "The Longest Common Subsequence is:\n";
    cout << a.getLCS() << endl;
    cout << endl;
    
    cout << "The DP matrix is as follows:\n";
    a.printDPmatrix();
    
    return 0;
}
