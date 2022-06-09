#include <stdio.h>
#include <stdint.h>

void getAttendance(uint32_t mask){
	for(int i = 0; i < 32; i++){
		if(((1<<i) & mask) == (1 << i))
			printf("Student with number %d is here\n", i+1);
		else
			printf("Student with number %d is not here\n", i+1);
	}
}

uint32_t setAttendance(uint32_t mask, int number){
	mask |= 1 << number - 1;
	return mask;
}

int32_t clearAttendance(uint32_t mask, int number){
	mask &= ~(1 << number - 1);
	return mask;
}

int32_t changeAttendance(uint32_t mask, int number){
	mask ^= (1 << number - 1);
	return mask;
}

int main(){
	uint32_t attendance = 0;
	int option = 0, student;
	while (true) {
		printf("1. Set attendance\n");
		printf("2. Clear attendance\n");
		printf("3. Attendance info\n");
		printf("4. Change attendance\n");
		printf("5. Exit\n");

		scanf("%d", &option);

		if(option == 1) {
			printf("Enter student number\n");
			scanf("%d", &student);
			attendance = setAttendance(attendance, student);
		} else if(option == 2) {
			printf("Enter student number\n");
			scanf("%d", &student);
			attendance = clearAttendance(attendance, student);
		} else if(option == 3) {
			getAttendance(attendance);
		} else if(option == 4) {
			printf("Enter student number\n");
			scanf("%d", &student);
			attendance = changeAttendance(attendance, student);
		} else if(option == 5) {
			break;
		}
	}
	return 0;
}