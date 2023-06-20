# Arduino Bluetooth Alarm Sistemi

Öncelikle bu JSON dosyasını Arduino IDE üzerine entegre etmeniz gerekiyor.
https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json
Bu JSON dosyasını Arduino IDE üzerinde "Files" sonrasında çıkan menüden "Preferences..." tuşlarına basın.
Açılan ekranda "Additional Board Manager URLs:" kısmındaki yere yukardaki linki yapıştırınız ve "OK"(OKEY) tuşuna basın.
Sonrasında "Tools" kısmından "Board:" yazan kısma gelin ve "Board Manager..." kısmnını seçin.
Soldan açılan ekranda "Filter your search..." kısmına stm32 yazın
Sonrasında Arduino IDE'nin kart yöneticisi kısmından STM32 paketlerini indirmeniz gerekiyor.
Şimdi Arduino kodlarını yüklemeye hazırız.


Aplikasyon için direkt olarak halihazırda olan apk dosyasını kurabilir veya uygulamayı düzenlemek için aşağıdaki adımları izleyebilirsiniz.
Öncelikle dosyalar içerisinde bulunan .aia uzantılı dosyayı bilgisayarınıza indirin.
Ardından MIT App Inventor 2'ye Google hesabınızla giriş yapın ve Create Apps tuşuna basın. 
Gelen ekranda yeni bir proje oluşturun. 
Oluşturduğunuz projeyi açıp bilgisayarınıza indirdiğiniz .aia uzantılı dosyayı "Projects" sekmesinin içindeki "Import project (.aia) from my computer ..." tuşuna basarak import edin.
