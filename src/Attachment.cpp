/*
 * Attachment.cpp
 *
 *  Created on: Nov 23, 2015
 *      Author: Rose
 */

#include <Attachment.h>

Attachment::Attachment(
      Shooter* shooter,
      Loader* loader):

      m_shooter(shooter),
      m_loader(loader){

}

// Checks all shooter/loader buttons and takes the necessary action(s)
void Attachment::checkAllButtons() {
   m_shooter->checkButton();
   //m_shooter->checkLoader();
   m_loader->updateLoader();
}

Attachment::~Attachment() {

}

