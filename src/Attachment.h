/*
 * Attachment.h
 *
 *  Created on: Nov 23, 2015
 *      Author: Rose
 */

/*
 * This class was created to facilitate the checking/updating
 * of buttons controlling shooter and loader operation, particularly
 * during teleoperated mode.
 */

#ifndef SRC_ATTACHMENT_H_
#define SRC_ATTACHMENT_H_
#include "Shooter.h"
#include "Loader.h"

class Attachment {
public:
   Shooter* m_shooter;
   Loader* m_loader;

   Attachment(
         Shooter* shooter,
         Loader* loader);
   virtual ~Attachment();

   void checkAllButtons();
};

#endif /* SRC_ATTACHMENT_H_ */
