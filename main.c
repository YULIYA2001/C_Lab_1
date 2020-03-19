#include <stdio.h>
#include <conio.h>

int main(void)
{
    char num, sign;
    int sum, i, check_not_num, check_enter, check_dots, check_first_last_dot;

    do
    {
        printf("Input a real number: ");
        num = '0';                  /* �������� ������������� ����� (�����������) */
        sum = 0;                    /* ����� 3-� ���� ����� ������� */
        check_enter = 0;            /* ����������� ����� ������ ������ (enter) */
        check_dots = 0;             /* ����������� ����� ����� 1 ����� */
        check_not_num = 0;          /* ��������� ��������� ����� */
        check_first_last_dot = 0;   /* ��������� ����� ������� ��� ���������� ������� "�����" */
        while (num != '\n')
        {
            scanf("%c", &num);
            /* �������� �� ������ ���� */
            check_enter++;
            /* �������� �� �������� ���� (�����, �����) */
            if (((num >= '0') && (num <= '9')) || (num == '.') || (num == '\n'));
            else
                check_not_num = 1;
            /* ������� ����� 3 ���� ����� ����� */
            if (num == '.')
            {
                /* �������� �� ������ ������ ����� (.111) */
                if (check_enter == 1)
                    check_first_last_dot = 1;
                else
                {
                    /* �������� �� ��������� ����� � ����� (11.111.111) */
                    check_dots++;
                    for (i = 0; i < 3; i++)
                    {
                        scanf("%c", &num);
                        /* �������� �� �������� ���� (�����, �����) ����� 3 ������ ����� ����� */
                        if (((num >= '0') && (num <= '9')) || (num == '\n'));
                        else
                            check_not_num = 1;
                        /* �������� �� ��������� ������ ����� (111.) */
                        if((i == 0) && (num == '\n'))
                            check_first_last_dot = 1;
                        if (num != '\n')
                            sum += (int)num - 48;
                        else
                            break;
                    }
                }
            }
        }
        if ((check_not_num == 1) || (check_enter == 1) || (check_dots > 1) || (check_first_last_dot == 1))
            printf("\nWrong input\n");
        else
        {
            printf("The sum of the first 3 digits of the fractional part of the number is ");
            printf("%d", sum);
        }
        printf("\nPress + to try again ");
        sign = getche();       /* ����� �� ������������ ����. ������� ����� */
        printf("\n");
    } while (sign == '+');
    _getch();
}
