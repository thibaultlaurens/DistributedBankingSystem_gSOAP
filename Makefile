
GSOAP=soapcpp2
SOAPH=stdsoap2.h
SOAPC=stdsoap2.c
SOAPCPP=stdsoap2.cpp
CC=gcc
CPP=g++
LIBS=
COFLAGS=-O2
CWFLAGS=-Wall
CIFLAGS=-I../..
CMFLAGS=
CFLAGS= $(CWFLAGS) $(COFLAGS) $(CIFLAGS) $(CMFLAGS)

all:		client bankaccount 

client:		bankaccount.h client.cpp $(SOAPH) $(SOAPCPP)
		$(GSOAP) -C bankaccount.h
		$(CPP) $(CFLAGS) -o client client.cpp soapC.cpp soapClient.cpp $(SOAPCPP) $(LIBS)

bankaccount:	bankaccount.h bankaccount.cpp $(SOAPH) $(SOAPCPP)
		$(GSOAP) -S bankaccount.h
		$(CPP) $(CFLAGS) -o bankaccount bankaccount.cpp soapC.cpp soapServer.cpp $(SOAPCPP) -lm $(LIBS) -lpthread

clean:
		rm -f client.exe account1.getAmount.req.xml account1.addMoney.res.xml account1.withdrawMoney.res.xml account1.nsmap account1.wsdl account1.xsd bankaccount.exe soapClientLib.cpp soapObject.h soapServerLib.cpp
		
		
		