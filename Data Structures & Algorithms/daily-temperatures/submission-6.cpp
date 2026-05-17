class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tempers) {
        int n = tempers.size();
        vector<int> res(n, 0); // Inizializziamo tutto a 0

        // Per ogni giorno...
        for (int i = 0; i < n; ++i) {
            // ...cerchiamo nei giorni successivi
            for (int j = i + 1; j < n; ++j) {
                // Appena troviamo un giorno più caldo
                if (tempers[j] > tempers[i]) {
                    res[i] = j - i; // Calcoliamo la distanza in giorni
                    break;          // Trovato il primo giorno più caldo, interrompiamo il ciclo interno
                }
            }
        }

        return res;
    }
};