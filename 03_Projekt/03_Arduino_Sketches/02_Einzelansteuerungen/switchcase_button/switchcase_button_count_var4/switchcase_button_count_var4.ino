byte pressCount = 0;

void loop () 
{
  static byte lastCount = 0;
  char customKey = customKeypad.getKey();
  if (customKey == '0')
  {
    ++pressCount %= 3;
  }
  if(lastCount != pressCount)
  {
    switch (pressCount) 
    {
      case 0:
        folderTrack(01, 004); // plays a song
        Serial.println(pressCount);
        Serial.print("case zero");
        break;
      case 1:
        folderTrack(01, 002); // plays a song
        Serial.println(pressCount);
        Serial.print("case one");
        break;
      case 2:
        folderTrack(01, 003);  // plays a song
        Serial.println(pressCount);
        Serial.print("case two");
        break;
    }
    lastCount = pressCount;
  }
}
