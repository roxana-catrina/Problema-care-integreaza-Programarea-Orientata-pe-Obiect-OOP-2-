Functionalitatile aplicatiei:

Să se creeze un program care permite crearea unui magazin, caracterizat prin nume și adresă.  Magazinul permite afișarea, vânzarea și respectiv re-alimentarea cu diverse produse.

Fiecare produs este caracterizat prin nume produs, cod produs, număr bucăți, preț. Produsele sunt împărțite în 3 categorii: produse alimentare (pentru care se mai cunoaște și termenul de expirare), electrocasnice (care la rândul lor sunt împărțite în 2 categorii: mari – se mai cunoaște și culoarea, și mici – se mai cunoaște puterea exprimată în Wh) și jucării (pentru o jucărie se mai cunoaște dacă este destinată pentru băieți sau pentru fete – folosind enumerare).

Astfel, programul afișează un meniu cu următoarele operațiuni:

1)     Afișare detalii magazin

2)     Inițializare produse magazin din fișierul „produse.txt”

3)     Afișarea tuturor produselor, sau la alegerea utilizatorului, afișarea filtrată:

Afișarea produselor alimentare
Afișarea electrocasnicelor
Afișarea jucăriilor

4)     Căutarea unui electrocasnic mare, după culoare

5)     Ștergerea unui produs după cod produs

6)     Sortarea produselor după preț crescător, respectiv descrescător

7)     Vânzarea unui produs prin salvarea lui într-un fișier produse_vândute.txt, împreună cu numele cumpărătorului, telefonul și adresa de livrare. Dacă stocul este 0, să se afișeze un mesaj corespunzător

8)     Calcularea și afișarea totalului pentru produsele vândute.

9)     Compararea celui mai scump produs cu ultimul produs din listă prin supraîncărcarea operatorului ==.

10)     Salvarea tuturor produselor disponibile din magazin în fișierul „produse.txt”

La vânzarea unui produs, să se verifice dacă numărul de telefon este valid și să se arunce o excepție în caz contrar, care va fi stocată în fișierul „log.txt”.

De asemenea, la toate operațiunile de introducere a datelor/ scriere, să se utilizeze supraîncărcarea operatorilor de intrare/ieșire.
