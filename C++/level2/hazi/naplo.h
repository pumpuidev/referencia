
#include <string>
#include <vector>

bool mindenkinek_ket_otos(const std::vector<std::vector<int> > &naplo);
int otosDb(const std::vector<int> &v);

void neveket_olvas(int n, const std::string &str, std::vector<std::string> &v);
void jegyeket_olvas(const std::vector<std::string> &tanulo, const std::vector<std::string> &targy, std::vector<std::vector<int> > &a);

void fajlbol_olvas(const std::string &fajlnev, std::vector<std::string> &tanulo, std::vector<std::string> &targy, std::vector<std::vector<int> > &naplo);

bool jegy(int k);
bool egykettoharom(int k);
