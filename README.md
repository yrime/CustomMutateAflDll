# CustomMutateAflDll

кастомная dll для генерационного фаззинга на основе winafl, позволяет внедрить свои генераторы входных параметров

## Внедрение

void mutate(u8* buf, u8* out_buf, u32 len)
  buf - старый тест кейс;
  out_buf - новый сгенерированный тест кейс
  len - размер тест кейса

## Запуск

afl-fuzz.exe -i IN -o OUT -t 5000+ -m none -Y -l testAfl.dll -- -- DumpWinAFL.exe "sumple.exe @@"
