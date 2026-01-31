class Team {
public:
	Team(int len = 100) { names = new char[maxNo = len]; }
	~Team() { delete[] names; }
protected:
	char* names;
	int maxNo;
};
class BaseballTeam : public Team {
public:
	BaseballTeam(const char s[], int si) : Team(si) {
		for (int i = 0; i<si; i++) names[i] = s[i];
	}
};
