#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cctype>
#include <algorithm>
#include <regex>

std::vector<std::string> gautiTeksta(std::ifstream &failas)
{
    std::vector<std::string> zodziai;

    std::string zodis;
    while (failas >> zodis)
    {
        zodziai.push_back(zodis);
    }

    return zodziai;
}

std::vector<std::string> gautiTLDs()
{
    std::vector<std::string> tlds;

    std::ifstream tldFailas("tlds.txt");

    std::string tld;
    while (tldFailas >> tld)
    {
        tlds.push_back(tld.insert(0, "."));
    }
    tldFailas.close();

    return tlds;
}

std::string formatuotiLinka(std::string linkas) {
    std::string result = linkas;

    while (!result.empty() && std::ispunct(result.back())) {
        result.pop_back();
    }
    return result;
}

bool turiTLD(std::string fullString, std::string phrase) {
    if (fullString.find(phrase) != std::string::npos) {
        fullString = formatuotiLinka(fullString);
        if (fullString.length() < phrase.length())
        {
            return false;
        }

        return fullString.substr(fullString.length() - phrase.length()) == phrase;
    } else {
        return false;
    }
}

std::vector<std::string> gautiLinkus(std::vector<std::string> &tekstas)
{
    std::vector<std::string> linkai;
    
    // Iš failo "tlds.txt" nuskaitomi visi šiuo metu užregistruoti "top level domains"
    std::vector<std::string> tlds = gautiTLDs();

    // Iteruojama per kiekvieną žodį
    for (auto zodis : tekstas)
    {
        for (auto tld : tlds)
        {
            if (turiTLD(zodis, tld))
            {
                linkai.push_back(formatuotiLinka(zodis));
            }
        }
    }

    tekstas.erase(std::remove_if(tekstas.begin(), tekstas.end(), [&tlds](const std::string& zodis)
    {
        return std::find(tlds.begin(), tlds.end(), zodis) != tlds.end();
        
    }), tekstas.end());

    return linkai;
}

std::string formatuotiZodi(std::string zodis)
{
    std::string suformatuotasZodis;
    
    for (char c : zodis) {
        if (!std::ispunct(static_cast<unsigned char>(c))) {
            suformatuotasZodis += c;
        }
    }
    
    return suformatuotasZodis;
}

bool neTekstas(const std::string& tekstas) {
    for (char c : tekstas) {
        if (!std::isalnum(c)) {
            return true;
        }
    }
    return false;
}

std::map<std::string, std::vector<int>> gautiZodziuMap(std::vector<std::string> tekstas)
{
    std::map<std::string, std::vector<int>> zodziai;

    int pozicija = 1;

    for (std::string &zodis : tekstas)
    {
        if (neTekstas(zodis)) continue;
        
        zodziai[formatuotiZodi(zodis)].push_back(pozicija);
        pozicija++;
    }

    return zodziai;
}

void isvestiLinkus(std::vector<std::string> linkai)
{
    std::ofstream failas("linkai.txt");

    for (auto linkas : linkai)
    {
        failas << linkas << std::endl;
    }

    failas.close();
}

void isvestiZodzius(std::map<std::string, std::vector<int>> zodziai)
{
    std::ofstream failas("zodziai.txt");

    for (const auto& irasas : zodziai) {
        const std::string& zodis = irasas.first;
        const std::vector<int>& pozicijos = irasas.second;

        if (pozicijos.size() < 2) continue;

        failas << zodis << " : " << pozicijos.size() << " | ";
        for (int pozicija : pozicijos)
        {
            failas << pozicija << " ";
        }
        failas << std::endl;
    }

    failas.close();
}

int main()
{
    // Nuskaityti tekstą
    std::ifstream failas("tekstas.txt");
    std::vector<std::string> tekstas = gautiTeksta(failas);
    failas.close();

    // Surinkti URLs
    std::vector<std::string> linkai = gautiLinkus(tekstas);

    // Surinkti pasikartojancius zodzius
    std::map<std::string, std::vector<int>> zodziai = gautiZodziuMap(tekstas);

    // Gautus rezultatus isvesti
    isvestiLinkus(linkai);
    isvestiZodzius(zodziai);

    return 0;
}