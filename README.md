# Objektinis Programavimas - Papildoma Užduotis
Užduoties formuluotė

    1. Suskaičiuokite, kiek kartų kiekvienas skirtingas žodis pasikartoja Jūsų tekste. Tekstą galite paimti iš bet kur, pvz.: Vikipediją straipsnį apie Vilnių (Geriau kad būtu kitoks tekstas, ne mažiau 1000 žodžių). Tuomet realizacijos output'e (išoriniame faile) išveskite skirtingus žodžius (kableliai, taškai ir kiti skyrybos ženklai nėra žodžiu dalis!), kurie pasikartojo dažniau negu 1 kartą, o taip pat ir count'erį, nurodantį kiek kartų konkretus žodis pasikartojo.
    2. Sukurkite cross-reference tipo lentelę kurioje būtų nurodyta, kurioje teksto vietoje (kurioje(-iose) teksto eilutėse) kiekvienas iš daugiau negu vieną kartą pasikartojantis žodis buvo paminėtas.
    3. URL adresų suradimas Jūsų tekste. Kaip ir pirmos užduoties atveju, tekstą galite paimti iš bet kur, račiau būtina, kad tame tekste būtų bent keli URL'ai, pateikti "pilnu" https://www.vu.lt/ ar "sutrumpintu" pavidalu: www.vu.lt. Jūsų tikslas, iš to teksto išrinkti visus šiuos URL'us ir grąžiai atspausdinti ekrane (ar išvesti į failą)!
    4. Repozicija turi būti parengta pagal visus ankstesnių darbų galutinėms versijoms galiojančius reikalavimus.

## Kaip veikia programa?
Programa nuskaito failą `tekstas.txt`, kuris yra jos root aplanke. Tekstas iš pradžių yra padalyjamas į atskirus žodžius, t.y. sukuriamas vektoriaus konteineris, kur kievienas žodis išsaugomas naujame vektoriaus indekse remiantis tuom, kad žodis priekyje ir gale turi tarpus tekste. Iš to išrinkto teksto tada yra trenkami link'ai. Vėliau tas pats tekstas yra suformatuojamas (pašalinami link'ai, skyrybos ženklai) yra tada yra pradedama skaičiuoti kiek kartų ir kokioje pozicijoje karotjasi bent 2 kartus tekste esantis žodis. 

SVARBU: Programai taip pat reikia `tlds.txt` failo, kuriame yra nurodyti visi arba dauguma „top-level domains“, kurio formatas turėtų būti toks:
```
com
net
eu
site
...
```
