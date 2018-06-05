#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_data_eeprom.c ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_operations.s ../../UserLibraries/MicrochipXC/L6474/L6474_Encoder.c ../../UserLibraries/MicrochipXC/Serial/lib_serial.c ../../UserLibraries/MicrochipXC/Serial/lib_spi.c main.c hal.c ui.c ../../UserLibraries/MicrochipXC/QEI/lib_qei.c ../../UserLibraries/MicrochipXC/utils/bin2str.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o ${OBJECTDIR}/_ext/2053695685/flash_operations.o ${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o ${OBJECTDIR}/_ext/1724012841/lib_serial.o ${OBJECTDIR}/_ext/1724012841/lib_spi.o ${OBJECTDIR}/main.o ${OBJECTDIR}/hal.o ${OBJECTDIR}/ui.o ${OBJECTDIR}/_ext/1764152896/lib_qei.o ${OBJECTDIR}/_ext/1195830012/bin2str.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d ${OBJECTDIR}/_ext/2053695685/flash_operations.o.d ${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o.d ${OBJECTDIR}/_ext/1724012841/lib_serial.o.d ${OBJECTDIR}/_ext/1724012841/lib_spi.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/hal.o.d ${OBJECTDIR}/ui.o.d ${OBJECTDIR}/_ext/1764152896/lib_qei.o.d ${OBJECTDIR}/_ext/1195830012/bin2str.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o ${OBJECTDIR}/_ext/2053695685/flash_operations.o ${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o ${OBJECTDIR}/_ext/1724012841/lib_serial.o ${OBJECTDIR}/_ext/1724012841/lib_spi.o ${OBJECTDIR}/main.o ${OBJECTDIR}/hal.o ${OBJECTDIR}/ui.o ${OBJECTDIR}/_ext/1764152896/lib_qei.o ${OBJECTDIR}/_ext/1195830012/bin2str.o

# Source Files
SOURCEFILES=../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_data_eeprom.c ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_operations.s ../../UserLibraries/MicrochipXC/L6474/L6474_Encoder.c ../../UserLibraries/MicrochipXC/Serial/lib_serial.c ../../UserLibraries/MicrochipXC/Serial/lib_spi.c main.c hal.c ui.c ../../UserLibraries/MicrochipXC/QEI/lib_qei.c ../../UserLibraries/MicrochipXC/utils/bin2str.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ32MC304
MP_LINKER_FILE_OPTION=,--script=../../UserLibraries/MicrochipXC/gld/p33FJ32MC304.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o: ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_data_eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2053695685" 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_data_eeprom.c  -o ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o: ../../UserLibraries/MicrochipXC/L6474/L6474_Encoder.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1156065970" 
	@${RM} ${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o.d 
	@${RM} ${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/L6474/L6474_Encoder.c  -o ${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724012841/lib_serial.o: ../../UserLibraries/MicrochipXC/Serial/lib_serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724012841" 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Serial/lib_serial.c  -o ${OBJECTDIR}/_ext/1724012841/lib_serial.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724012841/lib_serial.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724012841/lib_serial.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724012841/lib_spi.o: ../../UserLibraries/MicrochipXC/Serial/lib_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724012841" 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Serial/lib_spi.c  -o ${OBJECTDIR}/_ext/1724012841/lib_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724012841/lib_spi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724012841/lib_spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/hal.o: hal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/hal.o.d 
	@${RM} ${OBJECTDIR}/hal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  hal.c  -o ${OBJECTDIR}/hal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/hal.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/hal.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ui.o: ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ui.o.d 
	@${RM} ${OBJECTDIR}/ui.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ui.c  -o ${OBJECTDIR}/ui.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ui.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ui.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1764152896/lib_qei.o: ../../UserLibraries/MicrochipXC/QEI/lib_qei.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1764152896" 
	@${RM} ${OBJECTDIR}/_ext/1764152896/lib_qei.o.d 
	@${RM} ${OBJECTDIR}/_ext/1764152896/lib_qei.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/QEI/lib_qei.c  -o ${OBJECTDIR}/_ext/1764152896/lib_qei.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1764152896/lib_qei.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1764152896/lib_qei.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1195830012/bin2str.o: ../../UserLibraries/MicrochipXC/utils/bin2str.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1195830012" 
	@${RM} ${OBJECTDIR}/_ext/1195830012/bin2str.o.d 
	@${RM} ${OBJECTDIR}/_ext/1195830012/bin2str.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/utils/bin2str.c  -o ${OBJECTDIR}/_ext/1195830012/bin2str.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1195830012/bin2str.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1195830012/bin2str.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o: ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_data_eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2053695685" 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_data_eeprom.c  -o ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o: ../../UserLibraries/MicrochipXC/L6474/L6474_Encoder.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1156065970" 
	@${RM} ${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o.d 
	@${RM} ${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/L6474/L6474_Encoder.c  -o ${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1156065970/L6474_Encoder.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724012841/lib_serial.o: ../../UserLibraries/MicrochipXC/Serial/lib_serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724012841" 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Serial/lib_serial.c  -o ${OBJECTDIR}/_ext/1724012841/lib_serial.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724012841/lib_serial.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724012841/lib_serial.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724012841/lib_spi.o: ../../UserLibraries/MicrochipXC/Serial/lib_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724012841" 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Serial/lib_spi.c  -o ${OBJECTDIR}/_ext/1724012841/lib_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724012841/lib_spi.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724012841/lib_spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/hal.o: hal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/hal.o.d 
	@${RM} ${OBJECTDIR}/hal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  hal.c  -o ${OBJECTDIR}/hal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/hal.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/hal.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ui.o: ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ui.o.d 
	@${RM} ${OBJECTDIR}/ui.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ui.c  -o ${OBJECTDIR}/ui.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ui.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ui.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1764152896/lib_qei.o: ../../UserLibraries/MicrochipXC/QEI/lib_qei.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1764152896" 
	@${RM} ${OBJECTDIR}/_ext/1764152896/lib_qei.o.d 
	@${RM} ${OBJECTDIR}/_ext/1764152896/lib_qei.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/QEI/lib_qei.c  -o ${OBJECTDIR}/_ext/1764152896/lib_qei.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1764152896/lib_qei.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1764152896/lib_qei.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1195830012/bin2str.o: ../../UserLibraries/MicrochipXC/utils/bin2str.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1195830012" 
	@${RM} ${OBJECTDIR}/_ext/1195830012/bin2str.o.d 
	@${RM} ${OBJECTDIR}/_ext/1195830012/bin2str.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/utils/bin2str.c  -o ${OBJECTDIR}/_ext/1195830012/bin2str.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1195830012/bin2str.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Os -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1195830012/bin2str.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/2053695685/flash_operations.o: ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_operations.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2053695685" 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_operations.o.d 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_operations.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_operations.s  -o ${OBJECTDIR}/_ext/2053695685/flash_operations.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/2053695685/flash_operations.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/2053695685/flash_operations.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/2053695685/flash_operations.o: ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_operations.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2053695685" 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_operations.o.d 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_operations.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_operations.s  -o ${OBJECTDIR}/_ext/2053695685/flash_operations.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/2053695685/flash_operations.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/2053695685/flash_operations.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../../UserLibraries/MicrochipXC/gld/p33FJ32MC304.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../../UserLibraries/MicrochipXC/gld/p33FJ32MC304.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
