/*
 * LabSetting.h
 *
 *  Created on: Oct 11, 2024
 *      Author: sloer
 */

#ifndef SRC_LABS_LABSETTING_H_
#define SRC_LABS_LABSETTING_H_

#define LAB_2


#if defined LAB_1
	#include "Lab-1/Lab-1.h"
	void Lab_loop(){
		Lab_loopL1();
	}

	void Lab_output(){
		Lab_outputL1();
	}

	void Lab_input(){
		Lab_inputL1();
	}

	void Lab_setup(){
		Lab_setupL1();
	}
#elif defined LAB_2
	#include "Lab-2/Lab-2.h"

	void Lab_loop(){
		Lab_loopL2();
	}

	void Lab_output(){
		Lab_outputL2();
	}

	void Lab_input(){
		Lab_inputL2();
	}

	void Lab_setup(){
		Lab_setupL2();
	}
#elif defined LAB_3
	#include "Lab-3/Lab-3.h"

	void Lab_loop(){
		Lab_loopL3();
	}

	void Lab_output(){
		Lab_outputL3();
	}

	void Lab_input(){
		Lab_inputL3();
	}

	void Lab_setup(){
		Lab_setupL3();
	}
#elif defined LAB_4
	#include "Lab-4/Lab-4.h"

	void Lab_loop(){
		Lab_loopL4();
	}

	void Lab_output(){
		Lab_outputL4();
	}

	void Lab_input(){
		Lab_inputL4();
	}

	void Lab_setup(){
		Lab_setupL4();
	}
#elif defined LAB_5
	#include "Lab-5/Lab-5.h"

	void Lab_loop(){
		Lab_loopL5();
	}

	void Lab_output(){
		Lab_outputL5();
	}

	void Lab_input(){
		Lab_inputL5();
	}

	void Lab_setup(){
		Lab_setupL5();
	}
#endif



#endif /* SRC_LABS_LABSETTING_H_ */
