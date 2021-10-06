class Solution {
    public String reversePrefix(String word, char ch) 
    {
        int l= word.length();
        int c=0,pos=0;
        String s1="",s2="",s3="";
        for(int i=0;i<l;i++)
        {
            char ch1=word.charAt(i);
            pos=i;
            if(ch1==ch)
            {
                c++;
                s1=s1+ch1;
                break;
            }
            else
            {
                s1=s1+ch1;
            }
        }
        if(c==0)
        {
            return s1;
        }
        
        
        if(c>0)
        {
            for(int i=pos;i>=0;i--)
        {
            s3=s3+s1.charAt(i);
        }
        
            for(int i=pos+1;i<l;i++)
            {
                s2=s2+(word.charAt(i));
            }
        }
        return (s3+s2);
    }
}