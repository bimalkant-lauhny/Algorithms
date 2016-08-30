import std.stdio;
import std.string;
import std.algorithm;

class LCS
{

    private string s1, s2; /* strings to be compared to find 
    longest common subsequence */

    private int lcsSize; // size of LCS

    private string lcs; // stores LCS

    private int dp[][]; // dp array for calculating lcs

    this(string i1, string i2)
    {
        this.s1 = i1;
        this.s2 = i2;

        int len1 = cast(int)s1.length;
        int len2 = cast(int)s2.length;

        dp = new int[][] (len1+1, len2+1);
    }

    private void calcLCS()
    {
        int len1 = cast(int)s1.length;
        int len2 = cast(int)s2.length;
           
        foreach(i; 1..len1+1)
        {
            foreach(j; 1..len2+1)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    public int[][] getDPmatrix()
    {
        return dp;
    }   
     
    public int getSizeLCS()
    {
        int len1 = cast(int)s1.length;
        int len2 = cast(int)s2.length;

        if(dp[len1][len2] == 0)
            calcLCS();

        return dp[len1][len2];
    }

    public string getLCS()
    {
        int len1 = cast(int)s1.length;
        int len2 = cast(int)s2.length;

        if(dp[len1][len2] == 0)
            calcLCS();

        char[] lcs;
        int i = len1;
        int j = len2;

        while(lcs.length != dp[len1][len2])
        {
            if(dp[i][j] == dp[i-1][j])
                i -= 1;
            else if(dp[i][j] == dp[i][j-1])
                j -= 1;
            else
            {
                lcs ~= s1[i-1];
                i -= 1;
                j -= 1;
            }
        }

        return cast(string)(lcs.reverse);
    }

    public void printDPmatrix()
    {
        int len1 = cast(int)s1.length;
        int len2 = cast(int)s2.length;

        foreach(i; 0..len1+1)
            writeln(dp[i]);
    }

}

void main()
{
    writeln("Enter string 1:");
    string input1 = strip(readln());
    
    writeln("Enter string 2:");
    string input2 = strip(readln());
    
    writeln("\nThe strings entered are:");
    writeln(input1);
    writeln(input2);
    writeln();

    auto a = new LCS(input1, input2);

    writeln("The length of Longest Common Subsequence:");
    writeln(a.getSizeLCS());
    writeln();

    writeln("The Longest Common Subsequence is:");
    writeln(a.getLCS());
    writeln();
    
    writeln("The DP matrix is as follows:");
    a.printDPmatrix();
}
