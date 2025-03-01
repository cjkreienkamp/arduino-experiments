void setup() {
  // put your setup code here, to run once:

  // FRICTION INPUTS
  float mu_w = 0.9;                     // [ ] wheel static friction (0.9)
  float mu_pk = 0.4;                    // [ ] payload kinetic friction (0.4)

  // CONSTANT INPUTS
  float g = 32.2;                       // [ft/s/s] acceleration due to gravity
  float vehMass = 16.9/g;               // [slug] mass of the vehicle
  float payMass = 29/g;                 // [slug] mass of the payload
  float targetSlip = 0.95;              // target percentage of slip
  float stopDist = 22.5;                // [ft] desired stopping distance

  // SWITCHING DISTANCE CALCULATIONS
  float maxTractiveForce = vehMass*g*mu_w;
  float maxAccel = (targetSlip*maxTractiveForce-payMass*g*mu_pk)/(vehMass + payMass);
  float payDecel = -g*mu_pk;
  float vehDecel = -targetSlip*g*mu_w;
  float maxDecel = min(max(payDecel,vehDecel),0);
  float switchDist = min(stopDist/(1-maxAccel/maxDecel),20);
  Serial.print(switchDist);
}

void loop() {
  // put your main code here, to run repeatedly:


  
}
