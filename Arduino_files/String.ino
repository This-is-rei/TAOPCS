// Send string pass through serial port. this way we put more task on MCU


String password = "Ntg7hk6hzp52YKeauyMud13XCAAKeoNtg7hk6hzp52YKeauyMud13XCAAKeoNtg7hk6hzp52YKeauyMud13XCAAKeoNtg7hk6hzp52YKeauyMud13XCAAKeoNtg7hk6hzp52YKeauyMud13XCAAKeoNtg7hk6hzp52YKeauyMud13XCAAKeoNtg7hk6hzp52YKeauyMud13XCAAKeo";
int f = 0;

void setup() {



    pinMode(A5, OUTPUT);           
    digitalWrite(A5, LOW); // LED PIN
    
    Serial.begin(9600);
}
void loop() {

  //input
  f=0;
  while (Serial.available() == 0) {}
  String input = Serial.readString();
  input.trim(); 

  //control
  digitalWrite(A5, HIGH);

  if (password == input){
    digitalWrite(A5, LOW);
    delay(500);
  } else{
    digitalWrite(A5, LOW);
    delay(500);
  }


}