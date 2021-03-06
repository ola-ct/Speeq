/*

    Copyright (c) 2015 Oliver Lau <ola@ct.de>, Heise Medien GmbH & Co. KG

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/


#ifndef __AUDIODECODER_H_
#define __AUDIODECODER_H_

#include <QObject>
#include <QIODevice>
#include <QAudioFormat>
#include <QScopedPointer>
#include <QMutex>
#include "global.h"

class AudioDecoderPrivate;


class AudioDecoder : public QIODevice
{
  Q_OBJECT

public:
  AudioDecoder(const QAudioFormat &format, QMutex *mutex, QObject *parent);
  ~AudioDecoder();

  void start(void);
  void stop(void);

  const SampleBufferType &sampleBuffer(void) const;

protected:
  qint64 readData(char *data, qint64 maxlen);
  qint64 writeData(const char *data, qint64 len);

private:
  QScopedPointer<AudioDecoderPrivate> d_ptr;
  Q_DECLARE_PRIVATE(AudioDecoder)
  Q_DISABLE_COPY(AudioDecoder)

};

#endif // __AUDIODECODER_H_
