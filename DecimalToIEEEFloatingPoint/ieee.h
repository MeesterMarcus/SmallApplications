unsigned getExpMask(unsigned exp);

unsigned getBias(unsigned exp);

unsigned getExp(unsigned exp, unsigned frac, unsigned x);

unsigned getFrac(unsigned exp, unsigned frac, unsigned x);

int getSign(unsigned exp, unsigned frac, unsigned x);

int isDenormalized(unsigned exp, unsigned frac, unsigned x);

int isNormalized(unsigned exp, unsigned frac, unsigned x);

int isInfinity(unsigned exp, unsigned frac, unsigned x);

int isNaN(unsigned exp, unsigned frac, unsigned x);

double getValueDenormalized(unsigned exp, unsigned frac, unsigned x);

double getValueNormalized(unsigned exp, unsigned frac, unsigned x);

double getValueInfinity(unsigned exp, unsigned frac, unsigned x);

double getValue(unsigned exp, unsigned frac, unsigned x);

char *getTypeString(unsigned exp, unsigned frac, unsigned x);

int createDataFile();

