// Last updated: 06/07/2026, 09:52:51
bool isWhite(char s) {
    return s == 'W';
}
class Solution
{
    public:
        int minimumRecolors(string blocks, int k)
        {
            int n = blocks.size();
            int curOpr = 0;

            for (int i = 0; i < k; i++)
            {
                if (isWhite(blocks[i])) {
                    curOpr++;
                }
            }
            int opr = curOpr;

            for( int i = k; i < n; i++){
                curOpr = isWhite(blocks[i]) ? curOpr + 1 : curOpr;
                curOpr = isWhite(blocks[i - k]) ? curOpr - 1 : curOpr;


                opr = min(opr, curOpr);
            }
            return opr;
        }
};