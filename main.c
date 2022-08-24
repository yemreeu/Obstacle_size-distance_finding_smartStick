#include <SimpleSDAudio.h>
int trig1= 2;
int echo1 = 7;
int trig2= 4;
int echo2 = 8;
int trig3= 3;
int echo3 = 5;
int trig4= A0;
int echo4 = A2;
long sure1;
long uzaklik1;
long sure2;
long uzaklik2;
long sure3;
long uzaklik3;
long sure4;
long uzaklik4;

void setup() {
  // put your setup code here, to run once:

  SdPlay.setSDCSPin(10); //SD Kart CS Pin

  if(!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER))
  {
    while(1);
  }

  pinMode(trig1, OUTPUT);
  pinMode(echo1,INPUT);
  
  pinMode(trig2, OUTPUT);
  pinMode(echo2,INPUT);

  pinMode(trig3, OUTPUT);
  pinMode(echo3,INPUT);

  pinMode(trig4, OUTPUT);
  pinMode(echo4,INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // 1.sensör
  digitalWrite(trig1, LOW);
  delayMicroseconds(5);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW); 
  sure1 = pulseIn(echo1, HIGH);
  uzaklik1= sure1 /29.1/2;
  Serial.print("uzaklik1:");
  Serial.println(uzaklik1);  
  
  
  //2.sensör
  digitalWrite(trig2, LOW);
  delayMicroseconds(5);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW); 
  sure2 = pulseIn(echo2, HIGH);
  uzaklik2= sure2 /29.1/2;
  Serial.print("uzaklik2:");
  Serial.println(uzaklik2);  
  
  //3.sensör
  digitalWrite(trig3, LOW);
  delayMicroseconds(5);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW); 
  sure3 = pulseIn(echo3, HIGH);
  uzaklik3= sure3 /29.1/2;
  Serial.print("uzaklik3:");
  Serial.println(uzaklik3);  
  
  //4.sensör
    digitalWrite(trig4, LOW);
  delayMicroseconds(5);
  digitalWrite(trig4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig4, LOW); 
  sure4 = pulseIn(echo4, HIGH);
  uzaklik4= sure4 /29.1/2;
  Serial.print("uzaklik4:");
  Serial.println(uzaklik4);  
  
  delay(500);
  


  if ((uzaklik4>=18 && uzaklik4<28 )&& uzaklik4<500)    // en asagidaki sensorüm, asagi merdiven 
   {
     asagi_basamaka();
   }
   
  else if ((uzaklik4>=28 && uzaklik4<40 )&& uzaklik4<500)    // en asagidaki sensorüm, asagi merdiven 
   {
     asagi_basamakb();
   }
   
  else if ((uzaklik4>=40 && uzaklik4<75 )&& uzaklik4<500)    // en asagidaki sensorüm, asagi merdiven 
   {
     asagi_basamakc();
   }
   
  else if ((uzaklik4>=75 && uzaklik4<120 )&& uzaklik4<500)    // en asagidaki sensorüm, asagi merdiven 
   {
     asagi_basamakd();
   }
                      
  else if(uzaklik1<30 && uzaklik2>30 && uzaklik3>30)  // yukari merdiven 25 cm önünde
   {  
     yukari_basamaka();
   }
                      
  else if(uzaklik1<50 && uzaklik2>60 && uzaklik3>60)  // yukari merdiven 50 cm önünde
   {  
     yukari_basamakb();
   }
                      
  else if(uzaklik1<100 && uzaklik2>120 && uzaklik3>120)  // yukari merdiven 1 m önünde
   {  
     yukari_basamakc();
   }

  else if(uzaklik1 < 50 && uzaklik2<50 && uzaklik3>50)
   {
     nesne();  // 15 santim önünde engel
   }
        
  else if((uzaklik1 >= 10 && uzaklik1<20)&&(uzaklik2 >= 10 && uzaklik2<20)&&(uzaklik3 >= 10 && uzaklik3<20))
   {
     onbescm();  // 15 santim önünde engel
   }
   
  else if((uzaklik1 >= 20 && uzaklik1<30)&&(uzaklik2>=20 && uzaklik2<30)&&(uzaklik3>=20 && uzaklik3<30))
   {
     yirmibescm();  // 25 santim önünde engel
   }
    
  else if((uzaklik1 >= 30 && uzaklik1<45)&&(uzaklik2>=30 && uzaklik2<45)&&(uzaklik3>=30 && uzaklik3<45))
   {
     otuzbescm();  // 35 santim önünde engel
   }
  
  else if((uzaklik1 >= 45 && uzaklik1<65)&&(uzaklik2 >= 45 && uzaklik2<65)&&(uzaklik3 >= 45 && uzaklik3<65))
   {
     ellicm();
   }
  
  else if((uzaklik1 >= 65 && uzaklik1<90)&&(uzaklik2 >= 65 && uzaklik2<90)&&(uzaklik3 >= 65 && uzaklik3<90))
   {
     yetmisbescm();
   }
      
  else if ((uzaklik1 >= 90 && uzaklik1<120)&&(uzaklik2 >=90 && uzaklik2<120)&&(uzaklik3 >=90 && uzaklik3<120)) // 1 metre ön engel
   {
     birmetre();
   } 
       
  else if ((uzaklik1 >= 120 && uzaklik1<160)&&(uzaklik2 >=120 && uzaklik2<160)&&(uzaklik3 >=120 && uzaklik3<160)) // 1,5 metre ön engel
   {
     yuzellicm();
   } 
       
  else if ((uzaklik1 >= 160 && uzaklik1<200)&&(uzaklik2 >=160 && uzaklik2<200)&&(uzaklik3 >=160 && uzaklik3<200)) // 2 metre ötede  engel
   {
     ikimetre();
   } 
            
  else if ((uzaklik1 >= 200 && uzaklik1<249)&&(uzaklik2 >=200 && uzaklik2<249)&&(uzaklik3 >=200 && uzaklik3<249)) // 2,5 metre ötede  engel
   {
     ikibucukmetre();
   } 
   
  else if ((uzaklik1 >= 249 && uzaklik1<300)&&(uzaklik2 >=249 && uzaklik2<300)&&(uzaklik3 >=249 && uzaklik3<300)) // 3 metre ötede  engel
   {
     ucmetre();
   } 
   
  else if ((uzaklik1 >= 300 && uzaklik1<400)&&(uzaklik2 >=300 && uzaklik2<300)&&(uzaklik3 >=300 && uzaklik3<400)) // 3ten fazla metre ötede  engel
   {
     ucmetredenuzak();
   } 

   

}

void asagi_basamaka()
{
  SdPlay.setFile("asag.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped())
  {
    ; 
  }
}

void asagi_basamakb()
{
  SdPlay.setFile("asagio.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped())
  {
    ; 
  }
}


void asagi_basamakc()
{
  SdPlay.setFile("yrmasagi.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped())
  {
    ; 
  }
}


void asagi_basamakd()
{
  SdPlay.setFile("asagim.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped())
  {
    ; 
  }
}


void yukari_basamaka()
{
  SdPlay.setFile("yukaria.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped()) // müzik bittiğinde tekrar çal
  {
    ; 
  }
}


void yukari_basamakb()
{
  SdPlay.setFile("yukarib.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped()) // müzik bittiğinde tekrar çal
  {
    ; 
  }
}

void yukaria();
{
  SdPlay.setFile("yukariia.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped()) // müzik bittiğinde tekrar çal
  {
    ; 
  }
}

void yukarib();
{
  SdPlay.setFile("yukariib.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped()) // müzik bittiğinde tekrar çal
  {
    ; 
  }
}

void yukari_basamakc()
{
  SdPlay.setFile("yukaric.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped()) // müzik bittiğinde tekrar çal
  {
    ; 
  }
}

void nesne()
{
  SdPlay.setFile("nesne.wav");
 SdPlay.play(); // seçilen dosyayı çal
 while(!SdPlay.isStopped()) // müzik bittiğinde tekrar çal
 {
   ; 
 }
}

void onbescm()
{
  SdPlay.setFile("onbes.wav");
 SdPlay.play(); // seçilen dosyayı çal
 while(!SdPlay.isStopped()) // müzik bittiğinde tekrar çal
 {
   ; 
 }
}

void yirmibescm()
{
  SdPlay.setFile("yirmibes.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped())
  {
    ; 
  }
}


void otuzbescm()
{
  SdPlay.setFile("otuzbes.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped()) 
  {
    ; 
  }
}

void ellicm()
{
  SdPlay.setFile("elli.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped())
  {
    ; 
  }
}


void yetmisbescm()
{
  SdPlay.setFile("ybes.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped())
  {
    ; 
  }
}

void birmetre()
{
  SdPlay.setFile("birmetre.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped())
  {
    ; 
  }
}

void yuzellicm()
{
  SdPlay.setFile("birbm.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped()) 
  {
    ; 
  }
}

void ikimetre()
{
  SdPlay.setFile("ikimetre.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped()) 
  {
    ; 
  }
}


void ikibucukmetre() // yeni yaptıgım
{
  SdPlay.setFile("ikibm.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped()) 
  {
    ; 
  }
}


void ucmetre() //
{
  SdPlay.setFile("ucmetre.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped()) 
  {
    ; 
  }
}

void ucmetredenuzak() // yeni yaptıgım
{
  SdPlay.setFile("ucmu.wav");
  SdPlay.play(); // seçilen dosyayı çal
  while(!SdPlay.isStopped()) 
  {
    ; 
  }
}