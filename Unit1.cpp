//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <Math.hpp>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString number1;
AnsiString number2;
AnsiString znak;
double a, a2;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
	static bool Created;
	if (!Created) {
		Created = true;
		for (int i = 0; i < 17; i++) {
			B[i] = new TButton(this);
			B[i]->Name = "Button" + (String)(i + 1);
			B[i]->Height = 50;
			B[i]->DragCursor = crHandPoint;

			if (i == 0 || i == 1 || i == 2) {
				B[i]->Top = 50;
				B[i]->Left = 18 + i * 75;
				B[i]->Caption = (String)(i + 1);
			}
			else if (i == 3 || i == 4 || i == 5) {
				B[i]->Top = 105;
				B[i]->Left = 18 + (i - 3) * 75;
				B[i]->Caption = (String)(i + 1);
			}
			else if (i == 6 || i == 7 || i == 8) {
				B[i]->Top = 160;
				B[i]->Left = 18 + (i - 6) * 75;
                B[i]->Caption = (String)(i + 1);
			}
			else if (i == 9 || i == 10 || i == 11) {
				B[i]->Top = 215;
				B[i]->Left = 18 + (i - 9) * 75;

                if (i == 9) {
					B[i]->Caption = "C";
				}
				else if (i == 10) {
					B[i]->Caption = (String)(0);
				}
				else if (i == 11) {
					B[i]->Caption = "=";
				}
			}
			else if (i == 12 || i == 13  || i == 14 || i == 15 || i == 16 || i == 17) {
				B[i]->Height = 36;
				B[i]->Top = 50 + (i - 12) * 36;
				B[i]->Left = 246;

                if (i == 12) {
					B[i]->Caption = "+";
				}
				else if (i == 13) {
					B[i]->Caption = "-";
				}
				else if (i == 14) {
					B[i]->Caption = "*";
				}
				else if (i == 15) {
					B[i]->Caption = "/";
				}
				else if (i == 16) {
					B[i]->Caption = ".";
				}
				else if (i == 17) {
					B[i]->Caption = "^^";
				}
			}

			B[i]->Parent = this;
            B[i]->OnClick = ButtonClick;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClick(TObject *Sender) {
	String Name = ((TButton *)Sender)->Name;
	int i = StrToInt(Name.SubString(7, 2));

	switch(i) {
		case 1:
			Label1->Caption = Label1->Caption + "1";
            break;
		case 2:
			Label1->Caption = Label1->Caption + "2";
			break;
		case 3:
			Label1->Caption = Label1->Caption + "3";
			break;
		case 4:
			Label1->Caption = Label1->Caption + "4";
			break;
		case 5:
			Label1->Caption = Label1->Caption + "5";
			break;
		case 6:
			Label1->Caption = Label1->Caption + "6";
			break;
		case 7:
			Label1->Caption = Label1->Caption + "7";
			break;
		case 8:
			Label1->Caption = Label1->Caption + "8";
			break;
		case 9:
			Label1->Caption = Label1->Caption + "9";
			break;
		case 10:
			Label1->Caption = "";
			break;
		case 11:
			Label1->Caption = Label1->Caption + "0";
			break;
		case 12:
			number2 = Label1->Caption;
			if(number1 != "" && number2 != "" && znak != ""){
				if(znak == "+")
					Label1->Caption = AnsiString(number1.ToDouble() + number2.ToDouble());
				if(znak == "-")
					Label1->Caption = AnsiString(number1.ToDouble() - number2.ToDouble());
				if(znak == "*")
					Label1->Caption = AnsiString(number1.ToDouble() * number2.ToDouble());
				if(znak == "^^")
					Label1->Caption = AnsiString(pow(number1.ToDouble(), number2.ToDouble()));
				if(znak == "/") {
					if (number2 != "0,0") {
						Label1->Caption = AnsiString(number1.ToDouble() / number2.ToDouble());
					}
					else {
						ShowMessage("Ошибка! Деление на ноль!");
                        Label1->Caption = "";
						break;
					}
                }

				number2 = "";
				znak = "";
				number1 = Label1->Caption;
				return;
			}

			number2 = "";
			znak = "";
			number1 = "";
			Label1->Caption = "";
			ShowMessage("Не достаточно данных повторите ввод сначала");
			break;
		case 13:
            znak = "+";
			number1 = Label1->Caption;
			Label1->Caption = "";
			break;
		case 14:
            znak = "-";
			number1 = Label1->Caption;
			Label1->Caption = "";
			break;
		case 15:
            znak = "*";
			number1 = Label1->Caption;
			Label1->Caption = "";
			break;
		case 16:
            znak = "/";
			number1 = Label1->Caption;
			Label1->Caption = "";
			break;
		case 17:
			Label1->Caption = Label1->Caption + ",";
			break;

			case 18:
			znak = "^^";
			number1 = Label1->Caption;
			Label1->Caption = "";
			break;

		default:
			ShowMessage("Неправильное действие!");
            break;
	}
}
