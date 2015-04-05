// this is the fist exercise of c++ primer plus chapter 13

// base class

#ifndef EXERCISE_1
#define EXERCISE_1

class Cd
{	// represent a CD disk
private:
	char performers[50];
	char label[20];
	int selections;		// number of selections
	double playtime;	// playing time in minutes
public:
	Cd(char *s1, char *s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;  // reports all CD data
	virtual Cd & operator=(const Cd & rc);
};

class Classic : public Cd
{
private:
    char primaryWork[100];  // the primary work on the CD

public:
    Classic(char * s0, char * s1, char *s2, int n ,double x);
    Classic(const Cd & rc, char * s0=NULL);
    Classic();
    Classic(const Classic & rc);
    virtual void Report() const;  // report all Classic Cd data
    virtual Classic & operator=(const Classic & rc);
};

#endif

