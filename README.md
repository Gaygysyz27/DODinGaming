# DODinGaming

#Data Oriented Design in Dezvoltarea de Jocuri

In primul rand, acest document va fi updatat ocazional in functie de progresul vostru si de discutiile de la curs/laborator. (Ultimul update 04-11-2025, sapt 6)

#Reguli de baza:

- Limbaje acceptate: C si C++

- Librarii acceptate: SDL, dear IMGUI (in caz ca va fi nevoie de altele, vor fi updatate aici)

- Codul trebuie sa fie scris de voi, nu ma intereseaza codul generat cu “AI”, prefer sa va bateti capul si sa imi aratati 10 linii de cod scrise de voi care functioneaza ok decat 100 scrise cu AI care functioneaza mai bine dar care nu stiti ce inseamna.

#Notare:

- Nu o sa avem un barem (doar pentru ca ar fi in dezavantajul vostru sa fiu “constrans” de un barem), daca doriti unul, putem sa discutam la curs

- Ma intereseaza sa vad ca ati lucrat la proiect si ati invatat ceva, calitatea este mai importanta decat cantitatea

- Nu este imperativ sa luati cele mai bune decizii de dezvoltare dar ma intereseaza ca atunci cand va pun o intrebare despre o bucata din codul vostru sa stiti ce ati scris sa imi argumentati logica.

- Vreau sa vad cod ordonat, cu nume de functii si variabile rationale si comentarii.

- Este mai important pentru mine sa dezvoltati corect decat sa dezvoltati mult

#Checkpoint-uri:

Dupa cum am vorbit la curs si la laborator, principala activitate practica la care o sa lucram pentru acest subiect este un proiect, aproximativ din saptamana 4-5 pana in saptamana 13-14.

Checkpoint-urile pentru acest proiect sunt urmatoarele:

#Saptamana 7 – verificare (fara notare) pentru Faza 1.

#Saptamana 9-10 – verificare (cu notare) pentru Faza 2.

#Saptamana 13-14 – verificare (cu notare) pentru Faza 3.

Ca directie generala (care nu trebuie respectata 100%, sunt deschis la alte abordari) va las aici cateva jocuri pe care putem sa le folosim ca exemplu de implementare: Vampire Survivors Brotato They Are Billions Beat Hazzard (1, 2, 3) Solar 2

#Faza 1 – Baza proiectului si test de implementare

Sa se dezvolte o aplicatie cu urmatoarele caracteristici:

1. sa fie incorporata in proiectul vostru libraria “SDL”

(optional “dead IMGUI” pentru UI)

2. sa se poata afisa pe ecran sprite-uri.

3. sa se poata selecta numarul de obiecte reprezentate pe ecran cu sprite-uri (pana la un maxim de 100 000 de obiecte)

4. sa se implementeze coliziune intre aceste obiecte

5. sa se implementeze un mod de a masura performanta programului (FPS-uri, memorie folosita etc.)

Punctele 3 si 4 trebuie implementate in doua moduri, Object Oriented si Data Oriented (DOAR PENTRU FAZA 1), de preferat sa putem sa schimbam in timp real intre cele doua optiuni.

#Faza 2 – Implementarea “Engine-ului” (arhitectura va fi discutata la curs)

Folosindu-ne de ce am invatat dezvoltand Faza 1, sa se implementeze un “Engine” care sa:

- Proceseze input

- Updateze starea aplicatiei

- Fie capabil sa faca rendering in mod eficient.

Alte elemente ce trebuie implementate sunt:

- Ideea de jucator, monstru, obiect in joc (platforma, obiect colectionabil etc)

- Bazandu-ne pe elementele pe care vrem sa le folosim, sa se implementeze un ECS


#Faza 3 – Extinderea Engine-ului si implementarea de elemente de Gameplay (vor fi discutate aceste potentiale features dar ca exemplu)

- Sa se implementeze o logica de game loop (ex. Am un personaj care are un HP, atunci cand HP ajunge la 0 se termina game loop-ul)

- Sa se implmenteze effecte (effect de explozie la impact, proiectile etc)

- Colectare de obiecte

- Scor

- Etc.
