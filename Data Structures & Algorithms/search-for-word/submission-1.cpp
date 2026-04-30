class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        if(board.size() == 0) return false;

        for(int i =  0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] != word[0]) continue;
                if(backtrack(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }

    //zelim da prosledjujem daljem backtrack-u indekse gde se nalazim u matrici, trenutnu rec, tj trenutna slova koja sam uzeo
    //preko te reci mogu da ispitam da li se ona sadrzi u pocetnom delu zadate reci

    bool backtrack(vector<vector<char>>& board, int red, int kolona, int trIndex, string word) {

        if(trIndex == word.size()) return true;

        if(red >= board.size() || red < 0) return false;
        if(kolona >= board[red].size() || kolona < 0) return false;//ako je nesto od ovoga tacno ispali smo iz opsega, vracamo se nazad
        if(board[red][kolona] != word[trIndex] || board[red][kolona] == '#') return false;
        
        board[red][kolona] = '#';

        bool res = backtrack(board, red + 1, kolona, trIndex + 1, word) ||
        backtrack(board, red - 1, kolona, trIndex + 1, word) ||
        backtrack(board, red, kolona + 1, trIndex + 1, word) ||
        backtrack(board, red, kolona - 1, trIndex + 1, word);

        board[red][kolona] = word[trIndex];//vracamo na staro, jer vise nismo na tom putu
        
        return res;

    }
};
