enum note { middleC, Csharp, Cflat };
class Instrument {
public:
	void play(note) const {}
};
class Duvacki : public Instrument {
};
void tune(Instrument& i) {
	// ...
	i.play(middleC);
}

int main()
{
	Duvacki flejta;
	tune(flejta); //upcasting
}



