/*! \file    log.h
 * \author   Jay Ridgeway <jayridge@gmail.com>
 * \copyright GNU General Public License v3
 * \brief    Buffered logging (headers)
 * \details  Implementation of a simple buffered logger designed to remove
 * I/O wait from threads that may be sensitive to such delays. Buffers are
 * saved and reused to reduce allocation calls. The logger output can then
 * be printed to stdout and/or a log file.
 *
 * \ingroup core
 * \ref core
 */

#ifndef _JANUS_LOG_H
#define _JANUS_LOG_H

#include <stdio.h>
#include <glib.h>

/*! \brief Buffered vprintf
* @param[in] format Format string as defined by glib
* @param[in] args Parameters to insert into formatted string
* \note This output is buffered and may not appear immediately on stdout. */
void janus_vprintf(const char *format, ...) G_GNUC_PRINTF(1, 2);
/*! \brief Log initialization
* \note This should be called before attempting to use the logger. A buffer
* pool and processing thread are created.
* @param console Whether the output should be printed on stdout or not
* @param logfile Log file to save the output to, if any
* @returns 0 in case of success, a negative integer otherwise */
int janus_log_init(gboolean console, const char *logfile);
/*! \brief Log destruction */
void janus_log_destroy(void);

#endif