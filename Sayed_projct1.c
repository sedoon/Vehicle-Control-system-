/*
 ============================================================================
 Name        : projct1.c
 Author      : Sayed ibrahim
 Version     : V.1
 Description : Vehicle Control system
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

void vehicle_sensors(char input);
char traffic_light(char color);
unsigned char Temp_temperature(unsigned char temp_room);
unsigned char engine_temperature(unsigned char engine_temp);

unsigned char x_speed (unsigned char temperature,unsigned char Vehicle_Speed);
unsigned char y_Speeed (unsigned char temperature,unsigned char Vehicle_Speed);







int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char input;

	while(1)
	{
		printf(" \n" );
		printf("a-Turn On the vehicle engine \n" );
		printf("b-Turn Off the vehicle engine\n" );
		printf("c-Quit the system            \n" );
		printf(" \n" );

		scanf("  %c",&input);
		switch(input)
		{
		printf(" \n" );
		case 'a': vehicle_sensors(input);
		break;

		case 'b':printf("Turn Off the vehicle engine\n" );
		break;

		case 'c':printf("Quit the system            \n" );
		return 0;

		default:printf("invalid a choice            \n" );
		}
	}


}
void vehicle_sensors(char input)
{
	unsigned char  Vehicle_Speed=100,Engine_Temperature=90,Room_Temperature=35,flag=0;
	int invalid_choice = 0;
	while(1)
	{


		printf(" \n" );
		printf("a-Turn Off the vehicle engine \n" );
		printf("b-Set the traffic light color \n" );
		printf("c-Set the room temperature    \n" );
		printf("d-Set the engine temperature  \n" );
		printf(" \n" );

		scanf("  %c",&input);

		printf(" \n" );

		switch(input)
		{
		printf(" \n" );
		case 'a':flag=1;
		break;

		case 'b': Vehicle_Speed=traffic_light( Vehicle_Speed);
		if (Vehicle_Speed==30)
		{
			Room_Temperature = x_speed (Room_Temperature,Vehicle_Speed);
			Engine_Temperature = y_Speeed ( Engine_Temperature,Vehicle_Speed);

			flag=2;
		}

		break;

		case 'c': Room_Temperature=Temp_temperature(Room_Temperature);
		if (Vehicle_Speed==30)
		{
			Room_Temperature=x_speed (Room_Temperature,Vehicle_Speed);
			Engine_Temperature = y_Speeed ( Engine_Temperature,Vehicle_Speed);

			flag=2;
		}

		break;

		case 'd':Engine_Temperature=engine_temperature( Engine_Temperature);
		if (Vehicle_Speed==30)
		{
			Room_Temperature=x_speed (Room_Temperature,Vehicle_Speed);
			Engine_Temperature = y_Speeed ( Engine_Temperature,Vehicle_Speed);

			flag=2;
		}
		break;

		default:invalid_choice = 1;
			printf("invalid a choice            \n" );

		break;
		}
		if(flag==1)
		{
			break;
		}

		printf(" \n" );
		if(invalid_choice == 1)
		{
			printf("Engine is OFF\n");
		}
		else
		{
			printf("Engine is ON\n");

			if( (Room_Temperature == 20)||(flag == 2) )
			{
				printf("AC is ON\n");
			}
			else
			{
				printf("Ac is OFF\n");
			}


			printf("Vehicle Speed: %d KM/HR\n",Vehicle_Speed);

			printf("Room Temperature: %d C\n",Room_Temperature);

			if( (Engine_Temperature == 125)||(flag == 2))
			{
				printf("Engine Temperature Controller State is ON\n");
			}
			else
			{
				printf("Engine Temperature Controller State is OFF\n");
			}
			printf("Engine Temperature: %d C\n",Engine_Temperature);

		}
	}
}
char traffic_light(char color)
{
	int vehicle_speed;
	printf("enter the required color\n");
	scanf("   %c",&color);

	switch(color )
	{
	case 'g':
	case 'G':vehicle_speed=100;
	break;

	case 'o':
	case 'O':vehicle_speed=30;
	break;

	case 'r':
	case 'R':vehicle_speed=0;
	break;
	default:printf("invalid  choice\n");


	}

	return vehicle_speed;
}
unsigned char Temp_temperature(unsigned char temp_room)
{

	printf("Enter the required room temperature\n");
	scanf("%d",&temp_room);
	if(temp_room < 10)
	{
		temp_room=20;
	}
	else if(temp_room > 30)
	{
		temp_room=20;
	}

	return temp_room;
}
unsigned char engine_temperature(unsigned char engine_temp)
{
	printf("Enter the required engine temperature.\n");
	scanf("%d",&engine_temp);
	if(engine_temp <100)
	{
		engine_temp=125;
	}
	else if(engine_temp > 150)
	{
		engine_temp=125;
	}



	return engine_temp;
}

unsigned char x_speed (unsigned char temperature,unsigned char Vehicle_Speed)
{

	if(Vehicle_Speed==30)temperature= (temperature *5)/4+1;

	return temperature;

}
unsigned char y_Speeed (unsigned char temperature,unsigned char Vehicle_Speed)
{
	if(Vehicle_Speed==30)temperature=(temperature *5)/4+1;

	return temperature;

}
