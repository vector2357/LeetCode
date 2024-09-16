class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int minn = 10000, tempo;

        sort(timePoints.begin(), timePoints.end());
        for(int i=1; i<timePoints.size(); i++) {
            int horaAtual = 10*(timePoints[i][0]-48) + timePoints[i][1]-48;
            int horaAnt = 10*(timePoints[i-1][0]-48) + timePoints[i-1][1]-48;
            int minAtual = 10*(timePoints[i][3]-48) + timePoints[i][4]-48;
            int minAnt = 10*(timePoints[i-1][3]-48) + timePoints[i-1][4]-48;

            if(horaAtual != horaAnt) {
                tempo = (60-minAnt) + minAtual + 60*(horaAtual-1-horaAnt);
            }
            else {
                tempo = minAtual - minAnt;
            }
            minn = min(minn, tempo);
        }
        int horaAtual = 10*(timePoints[0][0]-48) + timePoints[0][1]-48 + 24;
        int horaAnt = 10*(timePoints[timePoints.size()-1][0]-48) + timePoints[timePoints.size()-1][1]-48;
        int minAtual = 10*(timePoints[0][3]-48) + timePoints[0][4]-48;
        int minAnt = 10*(timePoints[timePoints.size()-1][3]-48) + timePoints[timePoints.size()-1][4]-48;
        tempo = (60-minAnt) + minAtual + 60*(horaAtual-1-horaAnt);
        minn = min(minn, tempo);

        return minn;
    }
};