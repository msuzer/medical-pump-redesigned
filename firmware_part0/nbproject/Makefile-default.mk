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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_operations_33E_24E.s ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_data_eeprom.c ../../UserLibraries/MicrochipXC/Ethernet/Ethernet.c ../../UserLibraries/MicrochipXC/Ethernet/socket.c ../../UserLibraries/MicrochipXC/Ethernet/w5500.c ../../UserLibraries/MicrochipXC/Ethernet/w5500_init.c ../../UserLibraries/MicrochipXC/Ethernet/wizchip_conf.c ../../UserLibraries/MicrochipXC/Serial/lib_spi.c ../../UserLibraries/MicrochipXC/Serial/lib_i2c.c ../../UserLibraries/MicrochipXC/Serial/lib_serial_new.c hal.c main.c ui.c ../../UserLibraries/MicrochipXC/utils/pic.c ../../UserLibraries/MicrochipXC/utils/bin2str.c ../../UserLibraries/MicrochipXC/DS1820B/1wire.c ../../UserLibraries/MicrochipXC/DS1820B/ds1820b.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o ${OBJECTDIR}/_ext/427602380/Ethernet.o ${OBJECTDIR}/_ext/427602380/socket.o ${OBJECTDIR}/_ext/427602380/w5500.o ${OBJECTDIR}/_ext/427602380/w5500_init.o ${OBJECTDIR}/_ext/427602380/wizchip_conf.o ${OBJECTDIR}/_ext/1724012841/lib_spi.o ${OBJECTDIR}/_ext/1724012841/lib_i2c.o ${OBJECTDIR}/_ext/1724012841/lib_serial_new.o ${OBJECTDIR}/hal.o ${OBJECTDIR}/main.o ${OBJECTDIR}/ui.o ${OBJECTDIR}/_ext/1195830012/pic.o ${OBJECTDIR}/_ext/1195830012/bin2str.o ${OBJECTDIR}/_ext/900276889/1wire.o ${OBJECTDIR}/_ext/900276889/ds1820b.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o.d ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d ${OBJECTDIR}/_ext/427602380/Ethernet.o.d ${OBJECTDIR}/_ext/427602380/socket.o.d ${OBJECTDIR}/_ext/427602380/w5500.o.d ${OBJECTDIR}/_ext/427602380/w5500_init.o.d ${OBJECTDIR}/_ext/427602380/wizchip_conf.o.d ${OBJECTDIR}/_ext/1724012841/lib_spi.o.d ${OBJECTDIR}/_ext/1724012841/lib_i2c.o.d ${OBJECTDIR}/_ext/1724012841/lib_serial_new.o.d ${OBJECTDIR}/hal.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/ui.o.d ${OBJECTDIR}/_ext/1195830012/pic.o.d ${OBJECTDIR}/_ext/1195830012/bin2str.o.d ${OBJECTDIR}/_ext/900276889/1wire.o.d ${OBJECTDIR}/_ext/900276889/ds1820b.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o ${OBJECTDIR}/_ext/427602380/Ethernet.o ${OBJECTDIR}/_ext/427602380/socket.o ${OBJECTDIR}/_ext/427602380/w5500.o ${OBJECTDIR}/_ext/427602380/w5500_init.o ${OBJECTDIR}/_ext/427602380/wizchip_conf.o ${OBJECTDIR}/_ext/1724012841/lib_spi.o ${OBJECTDIR}/_ext/1724012841/lib_i2c.o ${OBJECTDIR}/_ext/1724012841/lib_serial_new.o ${OBJECTDIR}/hal.o ${OBJECTDIR}/main.o ${OBJECTDIR}/ui.o ${OBJECTDIR}/_ext/1195830012/pic.o ${OBJECTDIR}/_ext/1195830012/bin2str.o ${OBJECTDIR}/_ext/900276889/1wire.o ${OBJECTDIR}/_ext/900276889/ds1820b.o

# Source Files
SOURCEFILES=../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_operations_33E_24E.s ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_data_eeprom.c ../../UserLibraries/MicrochipXC/Ethernet/Ethernet.c ../../UserLibraries/MicrochipXC/Ethernet/socket.c ../../UserLibraries/MicrochipXC/Ethernet/w5500.c ../../UserLibraries/MicrochipXC/Ethernet/w5500_init.c ../../UserLibraries/MicrochipXC/Ethernet/wizchip_conf.c ../../UserLibraries/MicrochipXC/Serial/lib_spi.c ../../UserLibraries/MicrochipXC/Serial/lib_i2c.c ../../UserLibraries/MicrochipXC/Serial/lib_serial_new.c hal.c main.c ui.c ../../UserLibraries/MicrochipXC/utils/pic.c ../../UserLibraries/MicrochipXC/utils/bin2str.c ../../UserLibraries/MicrochipXC/DS1820B/1wire.c ../../UserLibraries/MicrochipXC/DS1820B/ds1820b.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24EP512GP806
MP_LINKER_FILE_OPTION=,--script="..\..\UserLibraries\MicrochipXC\gld\p24EP512GP806.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o: ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_data_eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2053695685" 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_data_eeprom.c  -o ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/427602380/Ethernet.o: ../../UserLibraries/MicrochipXC/Ethernet/Ethernet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427602380" 
	@${RM} ${OBJECTDIR}/_ext/427602380/Ethernet.o.d 
	@${RM} ${OBJECTDIR}/_ext/427602380/Ethernet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Ethernet/Ethernet.c  -o ${OBJECTDIR}/_ext/427602380/Ethernet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/427602380/Ethernet.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/427602380/Ethernet.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/427602380/socket.o: ../../UserLibraries/MicrochipXC/Ethernet/socket.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427602380" 
	@${RM} ${OBJECTDIR}/_ext/427602380/socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/427602380/socket.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Ethernet/socket.c  -o ${OBJECTDIR}/_ext/427602380/socket.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/427602380/socket.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/427602380/socket.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/427602380/w5500.o: ../../UserLibraries/MicrochipXC/Ethernet/w5500.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427602380" 
	@${RM} ${OBJECTDIR}/_ext/427602380/w5500.o.d 
	@${RM} ${OBJECTDIR}/_ext/427602380/w5500.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Ethernet/w5500.c  -o ${OBJECTDIR}/_ext/427602380/w5500.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/427602380/w5500.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/427602380/w5500.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/427602380/w5500_init.o: ../../UserLibraries/MicrochipXC/Ethernet/w5500_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427602380" 
	@${RM} ${OBJECTDIR}/_ext/427602380/w5500_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/427602380/w5500_init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Ethernet/w5500_init.c  -o ${OBJECTDIR}/_ext/427602380/w5500_init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/427602380/w5500_init.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/427602380/w5500_init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/427602380/wizchip_conf.o: ../../UserLibraries/MicrochipXC/Ethernet/wizchip_conf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427602380" 
	@${RM} ${OBJECTDIR}/_ext/427602380/wizchip_conf.o.d 
	@${RM} ${OBJECTDIR}/_ext/427602380/wizchip_conf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Ethernet/wizchip_conf.c  -o ${OBJECTDIR}/_ext/427602380/wizchip_conf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/427602380/wizchip_conf.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/427602380/wizchip_conf.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724012841/lib_spi.o: ../../UserLibraries/MicrochipXC/Serial/lib_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724012841" 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Serial/lib_spi.c  -o ${OBJECTDIR}/_ext/1724012841/lib_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724012841/lib_spi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724012841/lib_spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724012841/lib_i2c.o: ../../UserLibraries/MicrochipXC/Serial/lib_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724012841" 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Serial/lib_i2c.c  -o ${OBJECTDIR}/_ext/1724012841/lib_i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724012841/lib_i2c.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724012841/lib_i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724012841/lib_serial_new.o: ../../UserLibraries/MicrochipXC/Serial/lib_serial_new.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724012841" 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_serial_new.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_serial_new.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Serial/lib_serial_new.c  -o ${OBJECTDIR}/_ext/1724012841/lib_serial_new.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724012841/lib_serial_new.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724012841/lib_serial_new.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/hal.o: hal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/hal.o.d 
	@${RM} ${OBJECTDIR}/hal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  hal.c  -o ${OBJECTDIR}/hal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/hal.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/hal.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ui.o: ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ui.o.d 
	@${RM} ${OBJECTDIR}/ui.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ui.c  -o ${OBJECTDIR}/ui.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ui.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ui.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1195830012/pic.o: ../../UserLibraries/MicrochipXC/utils/pic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1195830012" 
	@${RM} ${OBJECTDIR}/_ext/1195830012/pic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1195830012/pic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/utils/pic.c  -o ${OBJECTDIR}/_ext/1195830012/pic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1195830012/pic.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1195830012/pic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1195830012/bin2str.o: ../../UserLibraries/MicrochipXC/utils/bin2str.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1195830012" 
	@${RM} ${OBJECTDIR}/_ext/1195830012/bin2str.o.d 
	@${RM} ${OBJECTDIR}/_ext/1195830012/bin2str.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/utils/bin2str.c  -o ${OBJECTDIR}/_ext/1195830012/bin2str.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1195830012/bin2str.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1195830012/bin2str.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/900276889/1wire.o: ../../UserLibraries/MicrochipXC/DS1820B/1wire.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/900276889" 
	@${RM} ${OBJECTDIR}/_ext/900276889/1wire.o.d 
	@${RM} ${OBJECTDIR}/_ext/900276889/1wire.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/DS1820B/1wire.c  -o ${OBJECTDIR}/_ext/900276889/1wire.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/900276889/1wire.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/900276889/1wire.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/900276889/ds1820b.o: ../../UserLibraries/MicrochipXC/DS1820B/ds1820b.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/900276889" 
	@${RM} ${OBJECTDIR}/_ext/900276889/ds1820b.o.d 
	@${RM} ${OBJECTDIR}/_ext/900276889/ds1820b.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/DS1820B/ds1820b.c  -o ${OBJECTDIR}/_ext/900276889/ds1820b.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/900276889/ds1820b.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/900276889/ds1820b.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o: ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_data_eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2053695685" 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_data_eeprom.c  -o ${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/2053695685/flash_data_eeprom.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/427602380/Ethernet.o: ../../UserLibraries/MicrochipXC/Ethernet/Ethernet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427602380" 
	@${RM} ${OBJECTDIR}/_ext/427602380/Ethernet.o.d 
	@${RM} ${OBJECTDIR}/_ext/427602380/Ethernet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Ethernet/Ethernet.c  -o ${OBJECTDIR}/_ext/427602380/Ethernet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/427602380/Ethernet.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/427602380/Ethernet.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/427602380/socket.o: ../../UserLibraries/MicrochipXC/Ethernet/socket.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427602380" 
	@${RM} ${OBJECTDIR}/_ext/427602380/socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/427602380/socket.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Ethernet/socket.c  -o ${OBJECTDIR}/_ext/427602380/socket.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/427602380/socket.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/427602380/socket.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/427602380/w5500.o: ../../UserLibraries/MicrochipXC/Ethernet/w5500.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427602380" 
	@${RM} ${OBJECTDIR}/_ext/427602380/w5500.o.d 
	@${RM} ${OBJECTDIR}/_ext/427602380/w5500.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Ethernet/w5500.c  -o ${OBJECTDIR}/_ext/427602380/w5500.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/427602380/w5500.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/427602380/w5500.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/427602380/w5500_init.o: ../../UserLibraries/MicrochipXC/Ethernet/w5500_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427602380" 
	@${RM} ${OBJECTDIR}/_ext/427602380/w5500_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/427602380/w5500_init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Ethernet/w5500_init.c  -o ${OBJECTDIR}/_ext/427602380/w5500_init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/427602380/w5500_init.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/427602380/w5500_init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/427602380/wizchip_conf.o: ../../UserLibraries/MicrochipXC/Ethernet/wizchip_conf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/427602380" 
	@${RM} ${OBJECTDIR}/_ext/427602380/wizchip_conf.o.d 
	@${RM} ${OBJECTDIR}/_ext/427602380/wizchip_conf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Ethernet/wizchip_conf.c  -o ${OBJECTDIR}/_ext/427602380/wizchip_conf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/427602380/wizchip_conf.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/427602380/wizchip_conf.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724012841/lib_spi.o: ../../UserLibraries/MicrochipXC/Serial/lib_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724012841" 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Serial/lib_spi.c  -o ${OBJECTDIR}/_ext/1724012841/lib_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724012841/lib_spi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724012841/lib_spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724012841/lib_i2c.o: ../../UserLibraries/MicrochipXC/Serial/lib_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724012841" 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Serial/lib_i2c.c  -o ${OBJECTDIR}/_ext/1724012841/lib_i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724012841/lib_i2c.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724012841/lib_i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724012841/lib_serial_new.o: ../../UserLibraries/MicrochipXC/Serial/lib_serial_new.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724012841" 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_serial_new.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724012841/lib_serial_new.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/Serial/lib_serial_new.c  -o ${OBJECTDIR}/_ext/1724012841/lib_serial_new.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724012841/lib_serial_new.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724012841/lib_serial_new.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/hal.o: hal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/hal.o.d 
	@${RM} ${OBJECTDIR}/hal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  hal.c  -o ${OBJECTDIR}/hal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/hal.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/hal.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ui.o: ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ui.o.d 
	@${RM} ${OBJECTDIR}/ui.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ui.c  -o ${OBJECTDIR}/ui.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ui.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ui.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1195830012/pic.o: ../../UserLibraries/MicrochipXC/utils/pic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1195830012" 
	@${RM} ${OBJECTDIR}/_ext/1195830012/pic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1195830012/pic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/utils/pic.c  -o ${OBJECTDIR}/_ext/1195830012/pic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1195830012/pic.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1195830012/pic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1195830012/bin2str.o: ../../UserLibraries/MicrochipXC/utils/bin2str.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1195830012" 
	@${RM} ${OBJECTDIR}/_ext/1195830012/bin2str.o.d 
	@${RM} ${OBJECTDIR}/_ext/1195830012/bin2str.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/utils/bin2str.c  -o ${OBJECTDIR}/_ext/1195830012/bin2str.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1195830012/bin2str.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1195830012/bin2str.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/900276889/1wire.o: ../../UserLibraries/MicrochipXC/DS1820B/1wire.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/900276889" 
	@${RM} ${OBJECTDIR}/_ext/900276889/1wire.o.d 
	@${RM} ${OBJECTDIR}/_ext/900276889/1wire.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/DS1820B/1wire.c  -o ${OBJECTDIR}/_ext/900276889/1wire.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/900276889/1wire.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/900276889/1wire.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/900276889/ds1820b.o: ../../UserLibraries/MicrochipXC/DS1820B/ds1820b.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/900276889" 
	@${RM} ${OBJECTDIR}/_ext/900276889/ds1820b.o.d 
	@${RM} ${OBJECTDIR}/_ext/900276889/ds1820b.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../UserLibraries/MicrochipXC/DS1820B/ds1820b.c  -o ${OBJECTDIR}/_ext/900276889/ds1820b.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/900276889/ds1820b.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/900276889/ds1820b.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o: ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_operations_33E_24E.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2053695685" 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o.d 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_operations_33E_24E.s  -o ${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax,-ah=${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.lst$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o: ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_operations_33E_24E.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2053695685" 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o.d 
	@${RM} ${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../../UserLibraries/MicrochipXC/FlashDataEEProm/flash_operations_33E_24E.s  -o ${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax,-ah=${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.lst$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/2053695685/flash_operations_33E_24E.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../../UserLibraries/MicrochipXC/gld/p24EP512GP806.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../../UserLibraries/MicrochipXC/gld/p24EP512GP806.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part0.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/MainBoard2.1Part0.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
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
