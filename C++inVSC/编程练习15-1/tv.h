#ifndef TV_H_
#define TV_H_

class Remote;
class Tv
{
	private:
		int state;
		int volume;
		int maxchannel;
		int channel;
		int mode;
		int input;
	public:
		friend class Remote;
		enum { Off, On };
		enum { MinVal, MaxVal = 20 };
		enum { Antenna, Cable };
		enum { TV, DVD }

		Tv(int s = Off, int mc = 125) : state(s), volume(5), Maxchannel(mc), channel(2), Model(Cable), input(TV) { }
		void onoff() { state = (state == On) ? Off : On;}
		bool ison() const { return state == On;}
		bool volop();
		bool voldown();
		void chanup();
		void chandown();
		void set_mode() { mode = (mode == Antenna)? Cable : Antenna;}
		void set_input() { input = (input == TV) ? DVD : TV;}
		void settings() const;
		bool ChangeRemteMode(Remote & r);
};


class Remote
{
	public:
		enum { Normal, Interactive };
		friend class Tv;
	private:
		int mode;
		int N_INmode;
	public:
		Remote(int m = Tv::TV, int n = Normal) : mode(m), N_INmode(n) { }
		bool volup(Tv& t) { return t.volup();}
		bool voldown(Tv& t) { return t.voldown();}
		void onoff(Tv& t) { t.onoff();}
		void chanup(Tv& t) { t.chanup(); }
		void chandown(Tv& t) { t.chandown(); }
		void set_chan(Tv& t, int c) { t.channel = c; }
		void set_mode(Tv& t) { t.set_mode();}
		void set_input(Tv& t) { t.set_input();}
		void displayMode() const;
};

#endif
