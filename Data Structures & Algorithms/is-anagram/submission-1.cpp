

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // 1. Controllo rapido: lunghezze diverse?
        if (s.length() != t.length()) {
            return false; // Stesso concetto di return False in Python/JS
        }

        // 2. Contiamo i caratteri
        // array di 26 interi, inizializzato a zero.
        // counts[0] conterà le 'a', counts[1] le 'b', ..., counts[25] le 'z'.
        std::array<int, 26> counts{}; // Equivalente a int counts[26] = {0};

        // Scorri la prima stringa 's' e incrementa i conteggi
        for (char c : s) { // Loop "range-based", come il for...of di JS o for...in di Python per liste
            // c è il carattere corrente
            // c - 'a' : Questo è un trucco comune. In C++, i caratteri hanno valori numerici
            // (ASCII o Unicode). 'b' - 'a' sarà 1, 'c' - 'a' sarà 2, ecc.
            // Quindi, 'a' corrisponde all'indice 0, 'b' all'indice 1, ecc.
            counts[c - 'a']++; // Incrementa il conteggio per quel carattere
        }

        // Scorri la seconda stringa 't' e decrementa i conteggi
        for (char c : t) {
            int index = c - 'a'; // Calcola l'indice per il carattere corrente

            // Decrementa il conteggio per quel carattere
            counts[index]--;

            // Se il conteggio scende sotto zero, 't' ha troppi di quel carattere
            if (counts[index] < 0) {
                return false; // Non sono anagrammi, esci subito
            }
        }

        // Se arriviamo qui, significa che per ogni carattere in 't', abbiamo trovato un
        // corrispondente carattere in 's' (e non abbiamo mai decrementato sotto zero).
        // Poiché abbiamo controllato all'inizio che le lunghezze siano uguali, questo
        // implica che tutti i conteggi rimanenti nell'array 'counts' DEVONO essere zero.
        // (Non serve un altro loop per controllare che tutti i counts[i] siano 0 grazie
        // al controllo iniziale della lunghezza e al controllo counts[index] < 0).

        // Se nessun controllo ha fallito, sono anagrammi
        return true; // Stesso concetto di return True in Python/JS
    }
};