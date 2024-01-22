#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <Windows.h>
#include <fstream>
#include <ctime>
	
using namespace std;

	int Rand(int min, int max);
	float LVLadmin = 0;
	int serverID = 0;
	int sizeTEXT = 28;
	string config = "config.txt";
	string NameAdminLVL = "Нету";
	string TagAdmin = "Нету";
	string NickName;
	int game = 0;
	int LVLup = 0;
	int game_over = 0;
	int over = 0;
	bool menu = true;
	int entrance = 0;
	int NumAdminTag;
	int NumAdminTagTotal;
	int KyratorTrue2;
	int day = 1;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int errorNUM = 0;
	int first = 0;
	int KyratorTrue1;

// Дополнение:
void Select_AdmTAG() {
		int GC_AP = rand() % 5;
		int GC_OPG = rand() % 5;
		int GC_GOCC = rand() % 5;
		int CGC_AP = rand() % 4;
		int CGC_OPG = rand() % 4;
		int CGC_GOCC = rand() % 4;
		int CX1 = rand() % 3;
		int CX2 = rand() % 3;
		int b_opg = rand() % 3;
		int a_opg = rand() % 3;
		int l_opg = rand() % 3;
		int PRAVO = rand() % 3;
		int YMBD = rand() % 3;
		int MO1 = rand() % 2;
		int MO2 = rand() % 2;
		int FCB = rand() % 3;
		int CB = rand() % 2;
		int FCIN = rand() % 2;
		int GIBDD = rand() % 2;
		int i = 0;
		int Cledaki[] = {GC_AP, GC_OPG, GC_GOCC, CGC_AP, CGC_OPG, CGC_GOCC, CX1, CX2, b_opg, a_opg, l_opg, PRAVO, YMBD, MO1, MO2, FCB, CB, GIBDD, FCIN};
		string CledakiName[] = {"ГС АП", "ГС ОПГ", "ГС ГОСС", "ЗГС АП", "ЗГС ОПГ", "ЗГС ГОСС", "След. АП", "След. АП", "След. Б-ОПГ", "След. А-ОПГ", "След. Л-ОПГ", "След. Право.", "След. УМВД", "След. МО", "След. МО", "След. ФСБ", "След. ЦБ", "След. ГИБДД", "След. ФСИН"};
		cout << "Должности: \n";
		cout << "-----------------------\n";
		while (19 > i) {
			cout << i + 1 << ". " << CledakiName[i];
			if (Cledaki[i] == 0) cout << " свободно.\n";
			else if (CledakiName[i] == TagAdmin) cout << " занято.\n";
			else cout << " занято.\n";
			i++;
		}
		cout << "20. Выйти в меню.\n";
		cout << "\n" << "Выберите цифру: ";
		cin >> NumAdminTag;
		NumAdminTag--;
		if (NumAdminTag < 0 || NumAdminTag > 19) {
			cout << "Некорректный ввод.\n";
		}
		else if (NumAdminTag == 20) {
			cout << "Вы покинули выбор должности.\n";
		}
		else if (NumAdminTag == 0 && TagAdmin != "ЗГС АП" || NumAdminTag == 1 && TagAdmin != "ЗГС ОПГ" || NumAdminTag == 2 && TagAdmin != "ЗГС ГОСС") {
			cout << "У вас недостаточный уровень Адм. Прав для данной должности.(Примечание: для должности ГС ГОСС/ОПГ/АП нужно отстоять пост на ЗГС ГОСС/ОПГ/АП)\n";
		}
		else if ((NumAdminTag == 4 || NumAdminTag == 5 || NumAdminTag == 6) && LVLadmin < 2.5) {
			cout << "Извините, чтобы встать на пост ЗГС, вам нужно:\n";
			cout << "Уровень Адм. Прав: 2.5 и выше\n";
		}
		else if (Cledaki[NumAdminTag] >= 1) {
			cout << "Извините должность занята.\n";
		}
		else if (Cledaki[NumAdminTag] == 0) {
			TagAdmin = CledakiName[NumAdminTag];
			cout << "Вы заняли должность: " << CledakiName[NumAdminTag] << endl;
			NumAdminTagTotal = NumAdminTag;
		}
	}
void event() {
	int help = 0;
	int event_true = 0;
	int EasyE = rand() % 9;
	int NormalE = rand() % 12;
	int HardE = rand() % 18;
	int ImpossibleE = rand() % 90;
	int LEAVE = rand() % 10000;
	if (LEAVE == 0) {
		LVLadmin = 0;
		menu = false;
		entrance == 1;
		over = 1;
		cout << "[EVENT]: Вы были сняты с поста по причине того что вы были замечены за ГРУБЫМ НАРУШЕНИЕМ!(Шанс: 1 к 10.000!)\n";
	}
	else if (ImpossibleE == 0 && LEAVE != 0) {
		cout << "[EVENT]: Вы сидите с другом в дискорде, рассказывая ему историю которая нарушает правила проекта в целом, и он говорит что зафрапсил.(Шанс 1 к 90)\n";
		cout << "[EVENT]: 1. Попросить его удалить фрапс.\n";
		cout << "[EVENT]: 2. Посмеяться и не поверить ему.\n";
		cout << "[EVENT]: 3. Продолжить рассказывать историю.\n";
		do {
			cout << "[" << NickName << "]: ";
			cin >> help;
			if (help == 1) {
				int unlucky = rand() % 3;
				if (unlucky == 0) {
					cout << "[EVENT]: Он правда сделал фрапс и отказался удалять его, и оформил на вас жалобу.(Вы сняты)\n";
					LVLadmin = 0;
					entrance = 1;
					over = 1;
				}
				else if(unlucky == 1) {
					cout << "[EVENT]: Он правда сделал фрапс и он удалил фрапс(Ничего)\n";
				}
				else {
					cout << "[EVENT]: Он не сделал фрапс, вам повезло.(Ничего)\n";
				}
			}
			else if (help == 2) {
				int unlucky = rand() % 2;
				if (unlucky == 0) {
					cout << "[EVENT]: Он зафрапсил и оформил жалобу.(Вы сняты)\n";
					LVLadmin = 0;
					entrance = 1;
					over = 1;
				}
				else {
					cout << "[EVENT]: Он не фрапсил, вам повезло(Ничего)\n";
				}
			}
			else if (help == 3) {
				int unlucky = rand() % 3;
				if (unlucky == 0) {
					cout << "[EVENT]: Вам не повезло, он оформил жалобу.(Вы сняты)\n";
					entrance = 1;
					over = 1;
					LVLadmin = 0;
				}
				else {
					cout << "[EVENT]: Вам повезло, он не фрапсил(Ничего.)\n";
				}
			}
			else {
				cout << "[ERROR]: Некорректный ввод.\n";
			}
		} while (help <= 0 || help >= 4);
	}
	else if (HardE == 0 && ImpossibleE != 0 && LEAVE != 0) {
		cout << "[EVENT]: Ваших родных оскорбил игрок в личные сообщение соц. сетей(Шанс 1 к 18)\n";
		cout << "[EVENT]: 1. Ответить ему тем же.\n";
		cout << "[EVENT]: 2. Проигнорировать\n";
		cout << "[EVENT]: 3. Занести его в ЧС\n";
		do {
			cout << "[" << NickName << "]: ";
			cin >> help;
			if (help == 1) {
				int lucky = rand() % 3;
				if (lucky == 0) {
					cout << "[EVENT]: Вам дико повезло, он не написал жалобу на вас и отстал от вас!(Ничего.)\n";
				}
				else {
					cout << "[EVENT]: Он написал жалобу на вас, и вы получили жесткое наказание(+70% к снятию и -100% к повышению)\n";
					LVLup = 0;
					game_over += 70;
					day = 0;
				}
			}
			else if (help == 2) {
				cout << "[EVENT]: После вашего игнорирование он начал больше оскорблять ваших родных.(Ничего.)\n";
			}
			else if (help == 3) {
				cout << "[EVENT]: После его занесения в ЧС, он больше не смог вам писать.(Ничего.)\n";
			}
		} while (help <= 0 || help >= 4);
	}
	else if (NormalE == 0 && HardE != 0 && ImpossibleE != 0 && LEAVE != 0 && KyratorTrue2 != 1) {
		cout << "[EVENT]: На собрании ваc упоминули и попросили рассказать последнии действия, НО вы тогда нарушали правила администрации.(Шанс 1 к 12)\n";
		cout << "[EVENT]: 1. Соврать.\n";
		cout << "[EVENT]: 2. Признаться и попытаться обьясниться.\n";
		cout << "[EVENT]: 3. Притвориться что выключился интернет.\n";
		do {
			cout << "[" << NickName << "]: ";
			cin >> help;
			if (help == 1) {
				cout << "[EVENT]: Вас расскретили! И вы получили выговор!(+20% к снятию и -20% к повышению)\n";
				LVLup -= 20;
				game_over += 20;
				day -= 4;
			}
			else  if (help == 2) {
				int lucky = rand() % 2;
				if (lucky == 0) {
					cout << "[EVENT]: Вам повезло, и вас простили!(Ничего)\n";
				}
				else if (lucky == 1) {
					cout << "[EVENT]: Вам не повезло, и вы получили предупреждение за признание!(-10% к повышению и +5% к снятию)\n";
					LVLup -= 10;
					game_over += 5;
					day -= 2;
				}
			}
			else if (help == 3) {
				cout << "[EVENT]: Руководство сервера было не тупой, и вы попались на обмане!(+50% к снятию)\n";
				game_over += 50;
			}
			else {
				cout << "[ERROR]: Некорректный ввод.\n";
			}
		} while (help <= 0 || help >= 4);
	}
	else if ((EasyE == 0 || EasyE == 4 || EasyE == 8) && NormalE != 0 && HardE != 0 && ImpossibleE != 0 && LEAVE != 0) {
		if (EasyE == 0) {
		cout << "[EVENT]: Вас попросили о помощи.(Шанс 1 к 3)\n";
		cout << "[EVENT]: 1. Помочь.\n";
		cout << "[EVENT]: 2. Отказать.\n";
			do {
				cout << "[" << NickName << "]: ";
				cin >> help;
				if (help == 1) {
					cout << "[EVENT]: Вас отблагодарили за помощь, так же это заметило руководство Сервера(+5% к повышению)\n";
					LVLup += 5;
					if (LVLadmin == 4) day++;
				}
				else if (help == 2) {
					cout << "[EVENT]: Вы отказали в помощи, так же это заметило руководство Сервера(-5% к повышению)\n";
					LVLup -= 5;
					if (LVLadmin == 4) day--;
				}
				else {
					cout << "[ERROR]: Некорректный ввод.\n";
				}
			} while (help <= 0 || help >= 3);
		}
		else if(EasyE == 4) {
			cout << "[EVENT]: Вас попросили помочь с фрапсом обзвона.(Шанс 1 к 3)\n";
			cout << "[EVENT]: 1. Помочь.\n";
			cout << "[EVENT]: 2. Отказать.\n";
			
			do {
				cout << "[" << NickName << "]: ";
				cin >> help;
				if (help == 1) {
					cout << "[EVENT]: Теперь вас уважает больше.(+3% к повышению)\n";
					LVLup += 3;
					if (LVLadmin == 4) day++;
				}
				if (help == 2) {
					cout << "[EVENT]: Ничего не произошло.(Ничего)\n";
				}
				else {
					cout << "[ERROR]: Некорректный ввод.\n";
				}
			} while (help <= 0 || help >= 3);
		}
		else {
			cout << "[EVENT]: Вас попросили зайти в игру и помочь с репортом.(Шанс 1 к 3)\n";
			cout << "[EVENT]: 1. Помочь.\n";
			cout << "[EVENT]: 2. Проигнорировать.\n";
			do {
				cout << "[" << NickName << "]: ";
				cin >> help;
				if (help == 1) {
					cout << "[EVENT]: Вас заметило руководство.(+5% к повышению)\n";
					LVLup += 5;
					if (LVLadmin == 4) day++;
				}
				else if (help == 2) {
					cout << "[EVENT]: Так как репорт не поменялся, весь состав получил коллективный выговор.(-10% к повышению)\n";
					LVLup -= 10;
				}
				else {
					cout << "[ERROR]: Некорректный ввод.\n";
				}
			} while (help <= 0 || help >= 3);
		}
	}
	else cout << "[EVENT]: Случайного события нету, вам повезло :)\n";
}

// game:
/* void Tex() {

}
void GA() {

}
void OZGA() {

} */
void ZGA() {

	cout << "!";

} 
int KyratorFirst = 0;
void Kyrator1() {

	KyratorTrue1 = 1;
	int LeaveMenu = 0;

			for (int movement = 0; movement != 3 && over != 1 && LeaveMenu != 1 && !(day >= 90); movement++) {
				int count;

				do {

					errorNUM = 0;
					cout << "Никнейм: " << NickName << "\n";
					cout << "Должность: " << NameAdminLVL << "\n";
					cout << "Уровень Адм. Прав: " << LVLadmin << "\n";
					cout << "Процент снятия: " << game_over << "%\n";
					cout << "Дней до Заместителя Главного Администратора: " << 90 - day << "\n";
					cout << "------------------------------------\n";
					cout << "1. Проверять деятельность администраторов.\n";
					cout << "2. Проверять жалобы на администрацию\n";
					cout << "3. Проверять деятельность Главных Следящих\n";
					cout << "4. Уйти с поста по собственному желанию.\n";
					cout << "5. Выйти в меню.\n";
					cin >> count;
					int adminMinus = rand() % 40;
					int adminHard = rand() % 10;

					if (count == 1 && num1 != 0) {

						cout << "Каждый пункт можно выполнить только ОДИН раз!!\n";
						cout << "\n";
						errorNUM++;

					}

					if (count == 2 && num2 != 0) {

						cout << "Каждый пункт можно выполнить только ОДИН раз!!\n";
						cout << "\n";
						errorNUM++;

					}

					if (count == 3 && num3 != 0) {

						cout << "Каждый пункт можно выполнить только ОДИН раз!!\n";
						cout << "\n";
						errorNUM++;

					}

					if (count == 1 && num1 == 0) {

						cout << "--------Итог проверки---------\n";
						if (adminMinus == 0) cout << "1 Администратор снят.\n";
						if (adminMinus == 1) cout << "Несколько Администраторов было снято.\n";
						if (adminMinus > 1) cout << "Не один Администратор не был снят.\n";

						if (adminHard == 0) cout << "1 Администратор получил наказание.\n";
						if (adminHard == 1) cout << "Несколько Администратор получило наказание.\n";
						if (adminHard > 1) cout << "Не один Администратор не получил наказание.\n";
						cout << "\n";
						num1++;

					}

					else if (count == 2 && num2 == 0) {

						cout << "--------Итог проверки---------\n";
						if (adminMinus == 0) cout << "1 Администратор снят.\n";
						if (adminMinus == 1) cout << "Несколько Администраторов было снято.\n";
						if (adminMinus > 1) cout << "Не один Администратор не был снят.\n";

						if (adminHard == 0) cout << "1 Администратор получил наказание.\n";
						if (adminHard == 1) cout << "Несколько Администратор получило наказание.\n";
						if (adminHard > 1) cout << "Не один Администратор не получил наказание.\n";
						cout << "\n";
						num2++;

					}

					else if (count == 3 && num3 == 0) {

						cout << "--------Итог проверки---------\n";
						int AdminNotNorma = rand() % 15;
						if (AdminNotNorma == 0 || AdminNotNorma == 1 || AdminNotNorma == 2) cout << "Несколько Главных Следящих получило наказание.\n";
						else if (AdminNotNorma == 3 || AdminNotNorma == 4 || AdminNotNorma == 5 || AdminNotNorma == 6 || AdminNotNorma == 7 || AdminNotNorma == 8 || AdminNotNorma == 9 || AdminNotNorma == 10) cout << "1 Главный Следящий получил наказание.\n";
						else cout << "Все потрудились на славу.\n";
						cout << "\n";
						num3++;

					}

					else if (count == 4) {

						over = 1;
						LVLadmin = 0;

					}

					else if (count == 5) {

						LeaveMenu = 1;

					}

					else if (count > 5 || count <= 0) {

						cout << "Некорректный ввод!\n";
						cout << "\n";

					}

					cout << "\n";

		} while ((count <= 0 || count > 5) && over != 1 && LeaveMenu != 1 || errorNUM != 0);
	}
} 
void Kyrator2() {
	if (KyratorFirst == 0) {

		cout << "ВНИМАНИЕ ДЛЯ ТОГО ЧТОБЫ НАЧАЛСЯ НОВЫЙ ДЕНЬ НУЖНО: \n";
		cout << "ВЫПОЛНИТЬ ВСЕ ДЕЙСТВИЯ ПО ОДНОМУ РАЗУ!\n";
		cout << "\n";
		system("pause");
		KyratorFirst++;

	}

	KyratorTrue2 = 1;
	int LeaveMenu = 0;

		for (day; over != 1 && LeaveMenu != 1 && KyratorTrue1 != 1 && KyratorTrue2 == 1; day++) {

			cout << "\n";
			cout << "НОВЫЙ ДЕНЬ! ДЕНЬ: " << day << "\n" << "\n";
			event();
			num1 = 0;
			num2 = 0;
			num3 = 0;

			for (int movement = 0; movement != 3 && over != 1 && LeaveMenu != 1 && day < 60; movement++) {

				int count;

				do {

					if (day >= 60 && KyratorTrue1 != 1) {
						cout << "Никнейм: " << NickName << "\n";
						cout << "Должность: " << NameAdminLVL << "\n";
						cout << "Уровень Адм. Прав: " << LVLadmin << "\n";
						cout << "Процент снятия: " << game_over << "%\n";
						cout << "Дней до Основного Куратора: СЕГОДНЯ)\n";
						cout << "------------------------------------\n";
						cout << "1. Повыситься :)\n";
						cout << "2. Повыситься :)\n";
						cout << "3. Повыситься :)\n";
						cout << "4. Уйти с поста по собственному желанию.\n";
						cout << "5. Выйти в меню.\n";
						int count;
						cin >> count;
						if (count >= 1 && count <= 3) {

							KyratorTrue1 = 1;
							KyratorTrue2 = 0;
							cout << "Поздравляю с повышением!!)\n";

						}

						else if (count == 4) {

							over = 1;
							LVLadmin = 0;

						}

						else if (count == 5) {

							LeaveMenu = 1;

						}

						else if (count > 5 || count <= 0) {

							cout << "Некорректный ввод!\n";
							cout << "\n";

						}

					}

					else {

						cout << "Никнейм: " << NickName << "\n";
						cout << "Должность: " << NameAdminLVL << "\n";
						cout << "Уровень Адм. Прав: " << LVLadmin << "\n";
						cout << "Процент снятия: " << game_over << "%\n";
						cout << "Дней до Основного Куратора: " << 60 - day << "\n";
						cout << "------------------------------------\n";
						cout << "1. Проверять деятельность Админов.\n";
						cout << "2. Проверять жалобы на администрацию\n";
						cout << "3. Проверить норматив Администрации\n";
						cout << "4. Уйти с поста по собственному желанию.\n";
						cout << "5. Выйти в меню.\n";

					}
					errorNUM = 0;
					int adminMinus = rand() % 40;
					int adminHard = rand() % 10;
					cin >> count;

					if (count == 1 && num1 != 0) {

						cout << "Каждый пункт можно выполнить только ОДИН раз!!\n";
						cout << "\n";
						errorNUM++;

					}

					if (count == 2 && num2 != 0) {

						cout << "Каждый пункт можно выполнить только ОДИН раз!!\n";
						cout << "\n";
						errorNUM++;

					}

					if (count == 3 && num3 != 0) {

						cout << "Каждый пункт можно выполнить только ОДИН раз!!\n";
						cout << "\n";
						errorNUM++;

					}

					if (count == 1 && num1 == 0) {

						cout << "--------Итог проверки---------\n";
						if (adminMinus == 0) cout << "1 Администратор снят.\n";
						if (adminMinus == 1) cout << "Несколько Администраторов было снято.\n";
						if (adminMinus > 1) cout << "Не один Администратор не был снят.\n";

						if (adminHard == 0) cout << "1 Администратор получил наказание.\n";
						if (adminHard == 1) cout << "Несколько Администратор получило наказание.\n";
						if (adminHard > 1) cout << "Не один Администратор не получил наказание.\n";
						cout << "\n";
						num1++;

					}

					else if (count == 2 && num2 == 0) {

						cout << "--------Итог проверки---------\n";
						if (adminMinus == 0) cout << "1 Администратор снят.\n";
						if (adminMinus == 1) cout << "Несколько Администраторов было снято.\n";
						if (adminMinus > 1) cout << "Не один Администратор не был снят.\n";

						if (adminHard == 0) cout << "1 Администратор получил наказание.\n";
						if (adminHard == 1) cout << "Несколько Администратор получило наказание.\n";
						if (adminHard > 1) cout << "Не один Администратор не получил наказание.\n";
						cout << "\n";
						num2++;

					}

					else if (count == 3 && num3 == 0) {

						cout << "--------Итог проверки---------\n";
						int AdminNotNorma = rand() % 15;
						if (AdminNotNorma == 0 || AdminNotNorma == 1 || AdminNotNorma == 2) cout << "Несколько Администраторов получило наказание.\n";
						else if (AdminNotNorma == 3 || AdminNotNorma == 4 || AdminNotNorma == 5 || AdminNotNorma == 6 || AdminNotNorma == 7 || AdminNotNorma == 8 || AdminNotNorma == 9 || AdminNotNorma == 10) cout << "1 Администратор получил наказание.\n";
						else cout << "Все потрудились на славу.\n";
						cout << "\n";
						num3++;

					}

					else if (count == 4) {

						over = 1;
						LVLadmin = 0;

					}

					else if (count == 5) {

						LeaveMenu = 1;

					}

					else if (count > 5 || count <= 0) {

						cout << "Некорректный ввод!\n";
						cout << "\n";

					}
					cout << "\n";

			} while ((count <= 0 || count > 5) && over != 1 && LeaveMenu != 1 || errorNUM != 0 && day < 60);
		}
	}
} 

void LVL_Adm3_5() {

	while (menu == true && LVLadmin == 3.5) {

		int luckyKYR = rand() % 120;

		if (game_over < 0) game_over = 0;

		if (game_over == 75) {
			cout << "Вы были сняты с поста!";
			over = 1;
			menu = false;
		}

		else if (over == 1) {

			menu = false;
			cout << "Вы были сняты с поста!";
		}

		else {

			cout << "Никнейм: " << NickName << "\n";
			cout << "Уровень Адм. Прав: " << LVLadmin << " | " << NameAdminLVL << "\n";
			cout << "Должность: " << TagAdmin << " | " << serverID << " Сервер\n";
			cout << "Процент снятия: " << game_over << "%\n";
			cout << "-----------------------------------------\n";
			cout << "1. Делать норматив.(-1% к снятию)\n";
			cout << "2. Отдыхать.(+12% к снятию)\n";
			if (luckyKYR == 0 && (TagAdmin == "ГС АП" || TagAdmin == "ГС ГОСС" || TagAdmin == "ГС ОПГ")) cout << "3. Встать на пост Куратора Администрации(Шанс 1 к 120)\n";
			else cout << "3. Ничего...\n";
			cout << "4. Выбрать должность.(" << TagAdmin << ")\n";
			cout << "5. Уход по собственному желанию.\n";
			cout << "6. Выйти в меню.\n";
			cin >> game;
			if (game == 1) {
				cout << "Вы сделали норматив!\n";
				game_over--;

			}

			else if (game == 2) {

				cout << "Вы славно отдохнули!\n";
				game_over += 12;

			}

			else if (game == 3) {

				if (luckyKYR == 0) {

					cout << "Вам выпал такой шанс... Как никак шанс 1 к 120!!!\n";
					cout << "Вы молодец что так упорно работаете!))\n";
					cout << "Поздравляю вас с повышением!!\n" << "\n";
					LVLadmin = 4;

				}

				else {

					cout << "Здесь правда ничего нету, но может появиться, я без понятия...\n" << "\n";

				}

			}
			else if (game == 4) {

				Select_AdmTAG();

			}

			else if (game == 5) {

				cout << "Вы ушли с поста по собственному желанию! Спасибо за работу\n";
				menu = false;
				entrance = 0;

			}

			else if (game == 6) {

				menu = false;

			}

			else cout << "Некорректный ввод!\n";

		}

		cout << "\n";
		event();

	}

}
void Lvl_Adm3() {

	while (menu == true && LVLadmin == 3) {

		if (LVLup < 0) LVLup = 0;

		else if (LVLup > 100) LVLup = 100;

		if (game_over < 0) game_over = 0;

		if (game_over == 80) {

			cout << "Вы были сняты с поста!";
			over = 1;
			menu = false;

		}
		else if (over == 1) {

			menu = false;
			cout << "Вы были сняты с поста!";

		}
		else {

			cout << "Никнейм: " << NickName << "\n";
			cout << "Уровень Адм. Прав: " << LVLadmin << " | " << NameAdminLVL << "\n";
			cout << "Должность: " << TagAdmin << " | " << serverID << " Сервер\n";
			cout << "Процент снятия: " << game_over << "%\n";
			cout << "-----------------------------------------\n";
			cout << "1. Делать норматив.(+3% к повышению)\n";
			cout << "2. Отдыхать.(-20% к повышению)\n";
			cout << "3. Повышение.(" << LVLup << "%)\n";
			cout << "4. Выбрать должность.(" << TagAdmin << ")\n";
			cout << "5. Уход по собственному желанию.\n";
			cout << "6. Выйти в меню.\n";
			cin >> game;

			if (game == 1) {

				cout << "Вы сделали норматив!\n";
				LVLup += 3;
				game_over--;

			}

			else if (game == 2) {

				cout << "Вы славно отдохнули!\n";
				LVLup -= 20;
				game_over += 15;

			}

			else if (game == 3) {

				cout << "Вы попросили повышение у Руководства сервера!\n";
				cout << "Итог: ";
				system("pause");
				if (LVLup >= 90) {
					cout << "Вас повысили!\n";
					LVLadmin = 3.5;
					LVLup = 0;
					menu = false;
					
				}

				else if (LVLup < 100) std::cout << "Вас не повысили\n";
			}

			else if (game == 4) {

				Select_AdmTAG();

			}

			else if (game == 5) {

				cout << "Вы ушли с поста по собственному желанию! Спасибо за работу\n";
				menu = false;
				entrance = 1;
				over = 1;

			}

			else if (game == 6) {

				menu = false;
				entrance = 0;

			}

			else cout << "Некорректный ввод!\n";

		}

		cout << "\n";
		event();

	}

}
void Lvl_Adm2_5() {

	if (first == 0) { 

		cout << "[EVENT]: ВНИМАНИЕ С ЭТОГО МОМЕНТА ДОСТУПНЫ СЛУЧАЙНЫЕ СОБЫТИЯ, БУДЬТЕ ОСТОРОЖНЫ!!!\n" << "\n"; 
		first = 1; 
	}

	while (menu == true && LVLadmin == 2.5) {

		if (LVLup < 0) LVLup = 0;

		else if (LVLup > 100) LVLup = 100;	

		if (game_over < 0) game_over = 0;

		if (game_over == 90) {

			cout << "Вы были сняты с поста!";
			over = 1;
			menu = false;

		}

		else if (over == 1) {

			menu = false;
			cout << "Вы были сняты с поста!";

		}

		else {

			cout << "Никнейм: " << NickName << "\n";
			cout << "Уровень Адм. Прав: " << LVLadmin << " | " << NameAdminLVL << "\n";
			cout << "Должность: " << TagAdmin << " | " << serverID << " Сервер\n";
			cout << "Процент снятия: " << game_over << "%\n";
			cout << "-----------------------------------------\n";
			cout << "1. Делать норматив.(+3% к повышению)\n";
			cout << "2. Отдыхать.(-15% к повышению)\n";
			cout << "3. Повышение.(" << LVLup << "%)\n";
			cout << "4. Выбрать должность.(" << TagAdmin << ")\n";
			cout << "5. Уход по собственному желанию.\n";
			cout << "6. Выйти в меню.\n";
			cin >> game;

			if (game == 1) {

				cout << "Вы сделали норматив!\n";
				LVLup += 3;
				game_over--;

			}

			else if (game == 2) {

				cout << "Вы славно отдохнули!\n";
				LVLup -= 15;
				game_over += 15;

			}

			else if (game == 3) {

				cout << "Вы попросили повышение у Руководства сервера!\n";
				cout << "Итог: ";
				system("pause");
				if (LVLup >= 90) {
					cout << "Вас повысили!\n";
					LVLadmin = 3;
					LVLup = 0;
					menu = false;

				}

				else if (LVLup < 100) std::cout << "Вас не повысили\n";

			}

			else if (game == 4) {

				Select_AdmTAG();

			}

			else if (game == 5) {

				cout << "Вы ушли с поста по собственному желанию! Спасибо за работу\n";
				menu = false;
				entrance = 1;
				over = 1;

			}

			else if (game == 6) {

				menu = false;
				entrance = 0;

			}

			else cout << "Некорректный ввод!\n";

		}

		cout << "\n";
		event();

	}

}
void Lvl_Adm2() {

	while (menu == true && LVLadmin == 2) {

		if (LVLup < 0) LVLup = 0;

		else if (LVLup > 100) LVLup = 100;

		if (game_over < 0) game_over = 0;

		if (game_over == 100) {

			cout << "Вы были сняты с поста!";
			over = 1;
			menu = false;

		}

		else if (over == 1) {

			menu = false;
			cout << "Вы были сняты с поста!";

		}

		else {

			cout << "Никнейм: " << NickName << "\n";
			cout << "Уровень Адм. Прав: " << LVLadmin << " | " << NameAdminLVL << "\n";
			cout << "Должность: " << TagAdmin << " | " << serverID << " Сервер\n";
			cout << "Процент снятия: " << game_over << "%\n";
			cout << "-----------------------------------------\n";
			cout << "1. Делать норматив.(+5% к повышению)\n";
			cout << "2. Отдыхать.(-10% к повышению)\n";
			cout << "3. Повышение.(" << LVLup << "%)\n";
			cout << "4. Выбрать должность.(" << TagAdmin << ")\n";
			cout << "5. Уход по собственному желанию.\n";
			cout << "6. Выйти в меню.\n";
			cin >> game;

			if (game == 1) {

				cout << "Вы сделали норматив!\n";
				LVLup += 5;
				game_over--;

			}

			else if (game == 2) {

				cout << "Вы славно отдохнули!\n";
				LVLup -= 10;
				game_over += 10;

			}

			else if (game == 3) {

				cout << "Вы попросили повышение у Руководства сервера!\n";
				cout << "Итог: ";
				system("pause");
				if (LVLup >= 90) {
					cout << "Вас повысили!\n";
					LVLadmin = 2.5;
					menu = false;
					LVLup = 0;

				}

				else if (LVLup < 100) std::cout << "Вас не повысили\n";

			}

			else if (game == 4) {

				Select_AdmTAG();

			}

			else if (game == 5) {

				cout << "Вы ушли с поста по собственному желанию! Спасибо за работу\n";
				menu = false;
				entrance = 1;
				over = 1;

			}

			else if (game == 6) {

				menu = false;
				entrance = 0;

			}

			else cout << "Некорректный ввод!\n";

		}

		cout << "\n";

	}

}

// menu:
void creators() {

	cout << "Разработчик: DEV_Fnuik\n";
	cout << "Мыслитель: Max_Maksov\n";
	cout << "Мыслитель: NelmoZ\n" << "\n";

}
void TEXT_INFO() {

	cout << "В этой игре вы почуствуете себя настоящим Администратором проекта Black Russia\n";
	cout << "Все начнется с Младшего Модератора, и будет завершено Спец. Администратором.\n";
	cout << "В лучшем случае, Командой Проекта, Разработчиком, Владельцем.\n";
	cout << "Можно начать идти так же не через Главного Администратора, а через Тех. Специалиста.\n";
	cout << "И многое другое)\n";
	system("pause");

}
void Text_Settings() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
	wcscpy(fontInfo.FaceName, L"Lucida Console");
	fontInfo.dwFontSize.Y = sizeTEXT;
	SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	Text_Settings();
	ofstream file;
	file.open(config);

	if (!file.is_open()) {

		cout << "Ошибка открытия файла!\n";
		return 0;

	}

	string password;
	int c;

	if (LVLadmin == 0) {

		cout << "Добро пожаловать в игру -Симулятор Администратора-\n";
		cout << "Примечание: Вводите данные на Английском Языке или будет плоха.\n";
		cout << "***ОЧЕНЬ ВАЖНО***  ДАННЫЕ НЕ СОХРАНЯЮТСЯ, ПОСЛЕ ВЫХОДА ВСЯ СТАТИСТИКА БУДЕТ ОБНУЛЕНА!\n";
		cout << "Для начало игры придумайте Никнейм(Имя_Фамилия, пример: Santa_Clever): ";
		cin >> NickName;
		cout << "Придумайте пароль: ";
		cin >> password;
		c = 1;

	}	

		string CheckPassword;
		int error = 0;

	do {

		cout << "Подтвердите пароль: ";
		cin >> CheckPassword;

		if (CheckPassword != password) error++;

		if (error == 1 && CheckPassword != password) cout << "Вы ввели пароль от аккаунта неправильно. У вас еще 2 попытки\n";

		else if (error == 2 && CheckPassword != password) cout << "Вы ввели пароль от аккаунта неправильно. У вас еще 1 попытка\n";

		else if (error == 3) {

			cout << "Вы ввели пароль от аккаунта 3 раза не правильно. Перезапустите игру.";
			return 0;

		}

	} while (CheckPassword != password);
	file << password << NickName;

	if (c == 1) {

		cout << "Пароль: " << password << " установлен.\n";
		cout << " \n";

	}
	int count = 0;
	do {

		menu = true;
		c = 0;
		if (over == 1) return 0;

		if (game == 1) game = 0;

		if (LVLadmin == 1)	NameAdminLVL = "Младший Модератор";
		else if (LVLadmin == 2)	NameAdminLVL = "Модератор";
		else if (LVLadmin == 2.5)	NameAdminLVL = "Старший Модератор";
		else if (LVLadmin == 3)	NameAdminLVL = "Администратор";
		else if (LVLadmin == 3.5)	NameAdminLVL = "Старший Администратор";
		else if (LVLadmin == 4)	NameAdminLVL = "Куратор Администрации";
		else if (LVLadmin == 4.5)	NameAdminLVL = "Заместитель Главного Администратора";
		else if (LVLadmin == 4.75)	NameAdminLVL = "Основной Заместитель Главного Администратора";
		else if (LVLadmin == 5)  NameAdminLVL = "Главный Администратор";

		if (entrance == 0 && serverID == 0) {

			cout << "Никнейм: " << NickName << "\n";
			cout << "---------Меню Игры---------\n";
			cout << "Для выбора пункта введите цифру\n";
			cout << "1. Начать игру\n";
			cout << "2. Настройки\n";
			cout << "3. В кратции о игре\n";
			cout << "4. Создатель\n";
			cout << "5. Выйти\n";
			cout << "Ваш выбор: ";

		}

		if (entrance == 0 && LVLadmin == 1) {

			cout << "Никнейм: " << NickName << "\n";
			cout << "Уровень Адм. Прав: " << LVLadmin << "\n";
			cout << "Должность: " << NameAdminLVL << " | " << serverID << " Сервер\n";
			cout << "---------Меню Игры---------\n";
			cout << "Для выбора пункта введите цифру\n";
			cout << "1. Продолжить игру\n";
			cout << "2. Настройки\n";
			cout << "3. В кратции о игре\n";
			cout << "4. Создатель\n";
			cout << "5. Выйти\n";
			cout << "Ваш выбор: ";

		}

		 if (entrance == 0 && LVLadmin >= 2 && LVLadmin < 4) {

			cout << "Никнейм: " << NickName << "\n";
			cout << "Уровень Адм. Прав: " << LVLadmin << " | " << NameAdminLVL << "\n";
			cout << "Должность: " << TagAdmin << " | " << serverID << " Сервер\n";
			cout << "---------Меню Игры---------\n";
			cout << "Для выбора пункта введите цифру\n";
			cout << "1. Продолжить игру\n";
			cout << "2. Настройки\n";
			cout << "3. В кратции о игре\n";
			cout << "4. Создатель\n";
			cout << "5. Выйти\n";
			cout << "Ваш выбор: ";

		}

		if (entrance == 0 && LVLadmin == 4) {

			cout << "Никнейм: " << NickName << "\n";
			cout << "Уровень Адм. Прав: " << LVLadmin << "\n";
			cout << "Должность: " << NameAdminLVL << " | " << serverID << " Сервер\n";
			cout << "---------Меню Игры---------\n";
			cout << "Для выбора пункта введите цифру\n";
			cout << "1. Продолжить игру\n";
			cout << "2. Настройки\n";
			cout << "3. В кратции о игре\n";
			cout << "4. Создатель\n";
			cout << "5. Выйти\n";
			cout << "Ваш выбор: ";

		}

		cin >> count;
		entrance = 1;

		if (count == 1) {

			if (serverID == 0) {

				do {

					cout << "Давайте выберем сервер(1 - 70): \n";
					cin >> serverID;

					if (serverID > 70 || serverID < 1) cout << "Введите корректное число сервера! ";

				} while (serverID <= 0 || serverID > 70);

				cout << "*Вас добавили в беседы: Admins FLOOD и Admins INFO & NEWS\n";
				cout << "\n";
				cout << "- Как же долго я этого ждал...\n";
				cout << "\n";
				LVLadmin = 1;
				entrance = 0;

			}

			if (serverID != 0 && entrance != 0) {

				while (menu && LVLadmin == 1) {

					if (LVLup < 0) LVLup = 0;

					else if (LVLup > 100) LVLup = 100;

					if (game_over < 0) game_over = 0;

					if (game_over == 100) {

						cout << "Вы были сняты с поста!";
						return 0;

					}

					else {

						cout << "Никнейм: " << NickName << "\n";
						cout << "Уровень Адм. Прав: " << LVLadmin << "\n";
						cout << "Должность: " << NameAdminLVL << " | " << serverID << " Сервер\n";
						cout << "Процент снятия: " << game_over << "%\n";
						cout << "-----------------------------------------\n";
						cout << "1. Делать норматив.(+5% к повышению)\n";
						cout << "2. Отдыхать.(-5% к повышению)\n";
						cout << "3. Повышение.(" << LVLup << "%)\n";
						cout << "4. Уход по собственному желанию.\n";
						cout << "5. Выйти в меню.\n";

						cin >> game;

							if (game == 1) {

								cout << "Вы сделали норматив!\n";
								LVLup += 5;
								game_over--;

							}

							else if (game == 2) {

								cout << "Вы славно отдохнули!\n";
								LVLup -= 5;
								game_over += 10;

							}

							else if (game == 3) {

								cout << "Вы попросили повышение у Руководства сервера!\n";
								cout << "Итог: ";
								system("pause");

								if (LVLup >= 90) {

									cout << "Вас повысили!\n";
									LVLadmin = 2;
									menu = false;

								}

								else if (LVLup < 100) std::cout << "Вас не повысили\n";

								if (LVLadmin == 2) LVLup = 0;

							}

							else if (game == 4) {

								cout << "Вы ушли с поста по собственному желанию! Спасибо за работу\n";
								return 0;

							}

							else if (game == 5) {

								menu = false;
							}

							else cout << "Некорректный ввод!\n";
						}

					cout << "\n";

					}

				if (LVLadmin == 2) {

					Lvl_Adm2();

				}

				else if (LVLadmin == 2.5) {

					Lvl_Adm2_5();

				}

				else if (LVLadmin == 3) {

					Lvl_Adm3();

				}

				else if (LVLadmin == 3.5) {

					LVL_Adm3_5();

				}

				else if (LVLadmin == 4 && KyratorTrue2 == 1) {

					Kyrator2();

				}

				else if (LVLadmin == 4 && KyratorTrue1 == 1) {

					Kyrator1();

				}

			}

			entrance = 0;

			}

			if (count == 2) {

				int otvet1 = 0;
				while (otvet1 == 0) {

					cout << "Введите размер шрифта. Текущий размер шрифта: " << sizeTEXT << "\n";
					cin >> sizeTEXT;
					Text_Settings();
					cout << "Оставляем?(1 - Да / 2 - Нет)";
					cin >> otvet1;

					if (otvet1 == 2) {

						sizeTEXT = 28;
						Text_Settings();

					}

					else cout << "Как скажете.\n";
					system("pause");
					entrance = 0;

				}

			}
			if (count == 3) {

				TEXT_INFO();
				entrance = 0;

			}

			if (count == 4) {

				creators();
				entrance = 0;
				system("pause");

			}

			if (count == 5) {

				int otvet;
				cout << "Вы точно хотите покинуть игру?(1 - Да / 2 - Нет): ";
				cin >> otvet;

				if (otvet == 1) return 0;

				else if (otvet == 2) {

					cout << "Вот и хорошо :)\n";
					cout << "\n";
					system("pause");
					entrance = 0;

				}

				else {

					cout << "Некорректный номер.\n";
					entrance = 0; 

				}

		} 

	} while (entrance == 0 && count >= 1 && count <= 5);

}


int Rand(int min, int max) {

	return (rand() % (max - min) + min);

}