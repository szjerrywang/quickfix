/* -*- C++ -*- */

/****************************************************************************
** Copyright (c) 2001-2014
**
** This file is part of the QuickFIX FIX Engine
**
** This file may be distributed under the terms of the quickfixengine.org
** license as defined by quickfixengine.org and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.quickfixengine.org/LICENSE for licensing information.
**
** Contact ask@quickfixengine.org if any conditions of this licensing are
** not clear to you.
**
****************************************************************************/

#ifndef FIX_NULLSTORE_H
#define FIX_NULLSTORE_H

#ifdef _MSC_VER
#pragma warning( disable : 4503 4355 4786 4290 )
#endif

#include "MessageStore.h"
#include "SessionSettings.h"
#include <string>

namespace FIX
{
class Session;

/**
 * Null implementation of MessageStore.
 *
 * Will not actually store messages.  Useful for admin-only or market
 * data-only applications.
 */
class NullStoreFactory : public MessageStoreFactory
{
public:
  MessageStore* create( const SessionID& );
  void destroy( MessageStore* );
};
/*! @} */


/**
 * Null implementation of MessageStore.
 *
 * Will not actually store messages.  Useful for admin-only or market
 * data-only applications.
 */
class NullStore : public MessageStore
{
public:
  NullStore() : m_nextSenderMsgSeqNum( 1 ), m_nextTargetMsgSeqNum( 1 ) {}

  /// @throws IOException
  bool set( int, const std::string& );
  /// @throws IOException
  void get( int, int, std::vector < std::string > & ) const;

  /// @throws IOException
  int getNextSenderMsgSeqNum() const
  { return m_nextSenderMsgSeqNum; }
  /// @throws IOException
  int getNextTargetMsgSeqNum() const
  { return m_nextTargetMsgSeqNum; }
  /// @throws IOException
  void setNextSenderMsgSeqNum( int value )
  { m_nextSenderMsgSeqNum = value; }
  /// @throws IOException
  void setNextTargetMsgSeqNum( int value )
  { m_nextTargetMsgSeqNum = value; }
  /// @throws IOException
  void incrNextSenderMsgSeqNum()
  { ++m_nextSenderMsgSeqNum; }
  /// @throws IOException
  void incrNextTargetMsgSeqNum()
  { ++m_nextTargetMsgSeqNum; }

  /// @throws IOException
  void setCreationTime( const UtcTimeStamp& creationTime )
  { m_creationTime = creationTime; }
  /// @throws IOException
  UtcTimeStamp getCreationTime() const
  { return m_creationTime; }

  /// @throws IOException
  void reset()
  {
    m_nextSenderMsgSeqNum = 1; m_nextTargetMsgSeqNum = 1;
    m_creationTime.setCurrent();
  }
  /// @throws IOException
  void refresh() {}

private:
  int m_nextSenderMsgSeqNum;
  int m_nextTargetMsgSeqNum;
  UtcTimeStamp m_creationTime;
};
}

#endif // FIX_NULLSTORE_H

