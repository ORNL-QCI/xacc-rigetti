
// Generated from Quil.g4 by ANTLR 4.7.1


#include "QuilListener.h"

#include "QuilParser.h"


using namespace antlrcpp;
using namespace quil;
using namespace antlr4;

QuilParser::QuilParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

QuilParser::~QuilParser() {
  delete _interpreter;
}

std::string QuilParser::getGrammarFileName() const {
  return "Quil.g4";
}

const std::vector<std::string>& QuilParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& QuilParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- QuilContext ------------------------------------------------------------------

QuilParser::QuilContext::QuilContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::QuilContext::EOF() {
  return getToken(QuilParser::EOF, 0);
}

std::vector<QuilParser::AllInstrContext *> QuilParser::QuilContext::allInstr() {
  return getRuleContexts<QuilParser::AllInstrContext>();
}

QuilParser::AllInstrContext* QuilParser::QuilContext::allInstr(size_t i) {
  return getRuleContext<QuilParser::AllInstrContext>(i);
}

std::vector<tree::TerminalNode *> QuilParser::QuilContext::NEWLINE() {
  return getTokens(QuilParser::NEWLINE);
}

tree::TerminalNode* QuilParser::QuilContext::NEWLINE(size_t i) {
  return getToken(QuilParser::NEWLINE, i);
}


size_t QuilParser::QuilContext::getRuleIndex() const {
  return QuilParser::RuleQuil;
}

void QuilParser::QuilContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuil(this);
}

void QuilParser::QuilContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuil(this);
}

QuilParser::QuilContext* QuilParser::quil() {
  QuilContext *_localctx = _tracker.createInstance<QuilContext>(_ctx, getState());
  enterRule(_localctx, 0, QuilParser::RuleQuil);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(83);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QuilParser::DEFGATE)
      | (1ULL << QuilParser::DEFCIRCUIT)
      | (1ULL << QuilParser::MEASURE)
      | (1ULL << QuilParser::LABEL)
      | (1ULL << QuilParser::HALT)
      | (1ULL << QuilParser::JUMP)
      | (1ULL << QuilParser::JUMPWHEN)
      | (1ULL << QuilParser::JUMPUNLESS)
      | (1ULL << QuilParser::RESET)
      | (1ULL << QuilParser::WAIT)
      | (1ULL << QuilParser::NOP)
      | (1ULL << QuilParser::INCLUDE)
      | (1ULL << QuilParser::PRAGMA)
      | (1ULL << QuilParser::FALSE)
      | (1ULL << QuilParser::TRUE)
      | (1ULL << QuilParser::NOT)
      | (1ULL << QuilParser::AND)
      | (1ULL << QuilParser::OR)
      | (1ULL << QuilParser::MOVE)
      | (1ULL << QuilParser::EXCHANGE)
      | (1ULL << QuilParser::IDENTIFIER))) != 0)) {
      setState(82);
      allInstr();
    }
    setState(93);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(86); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(85);
          match(QuilParser::NEWLINE);
          setState(88); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == QuilParser::NEWLINE);
        setState(90);
        allInstr(); 
      }
      setState(95);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(99);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == QuilParser::NEWLINE) {
      setState(96);
      match(QuilParser::NEWLINE);
      setState(101);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(102);
    match(QuilParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AllInstrContext ------------------------------------------------------------------

QuilParser::AllInstrContext::AllInstrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QuilParser::DefGateContext* QuilParser::AllInstrContext::defGate() {
  return getRuleContext<QuilParser::DefGateContext>(0);
}

QuilParser::DefCircuitContext* QuilParser::AllInstrContext::defCircuit() {
  return getRuleContext<QuilParser::DefCircuitContext>(0);
}

QuilParser::InstrContext* QuilParser::AllInstrContext::instr() {
  return getRuleContext<QuilParser::InstrContext>(0);
}


size_t QuilParser::AllInstrContext::getRuleIndex() const {
  return QuilParser::RuleAllInstr;
}

void QuilParser::AllInstrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAllInstr(this);
}

void QuilParser::AllInstrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAllInstr(this);
}

QuilParser::AllInstrContext* QuilParser::allInstr() {
  AllInstrContext *_localctx = _tracker.createInstance<AllInstrContext>(_ctx, getState());
  enterRule(_localctx, 2, QuilParser::RuleAllInstr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(107);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QuilParser::DEFGATE: {
        enterOuterAlt(_localctx, 1);
        setState(104);
        defGate();
        break;
      }

      case QuilParser::DEFCIRCUIT: {
        enterOuterAlt(_localctx, 2);
        setState(105);
        defCircuit();
        break;
      }

      case QuilParser::MEASURE:
      case QuilParser::LABEL:
      case QuilParser::HALT:
      case QuilParser::JUMP:
      case QuilParser::JUMPWHEN:
      case QuilParser::JUMPUNLESS:
      case QuilParser::RESET:
      case QuilParser::WAIT:
      case QuilParser::NOP:
      case QuilParser::INCLUDE:
      case QuilParser::PRAGMA:
      case QuilParser::FALSE:
      case QuilParser::TRUE:
      case QuilParser::NOT:
      case QuilParser::AND:
      case QuilParser::OR:
      case QuilParser::MOVE:
      case QuilParser::EXCHANGE:
      case QuilParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(106);
        instr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstrContext ------------------------------------------------------------------

QuilParser::InstrContext::InstrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QuilParser::GateContext* QuilParser::InstrContext::gate() {
  return getRuleContext<QuilParser::GateContext>(0);
}

QuilParser::MeasureContext* QuilParser::InstrContext::measure() {
  return getRuleContext<QuilParser::MeasureContext>(0);
}

QuilParser::DefLabelContext* QuilParser::InstrContext::defLabel() {
  return getRuleContext<QuilParser::DefLabelContext>(0);
}

QuilParser::HaltContext* QuilParser::InstrContext::halt() {
  return getRuleContext<QuilParser::HaltContext>(0);
}

QuilParser::JumpContext* QuilParser::InstrContext::jump() {
  return getRuleContext<QuilParser::JumpContext>(0);
}

QuilParser::JumpWhenContext* QuilParser::InstrContext::jumpWhen() {
  return getRuleContext<QuilParser::JumpWhenContext>(0);
}

QuilParser::JumpUnlessContext* QuilParser::InstrContext::jumpUnless() {
  return getRuleContext<QuilParser::JumpUnlessContext>(0);
}

QuilParser::ResetStateContext* QuilParser::InstrContext::resetState() {
  return getRuleContext<QuilParser::ResetStateContext>(0);
}

QuilParser::WaitContext* QuilParser::InstrContext::wait() {
  return getRuleContext<QuilParser::WaitContext>(0);
}

QuilParser::ClassicalUnaryContext* QuilParser::InstrContext::classicalUnary() {
  return getRuleContext<QuilParser::ClassicalUnaryContext>(0);
}

QuilParser::ClassicalBinaryContext* QuilParser::InstrContext::classicalBinary() {
  return getRuleContext<QuilParser::ClassicalBinaryContext>(0);
}

QuilParser::NopContext* QuilParser::InstrContext::nop() {
  return getRuleContext<QuilParser::NopContext>(0);
}

QuilParser::IncludeContext* QuilParser::InstrContext::include() {
  return getRuleContext<QuilParser::IncludeContext>(0);
}

QuilParser::PragmaContext* QuilParser::InstrContext::pragma() {
  return getRuleContext<QuilParser::PragmaContext>(0);
}


size_t QuilParser::InstrContext::getRuleIndex() const {
  return QuilParser::RuleInstr;
}

void QuilParser::InstrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstr(this);
}

void QuilParser::InstrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstr(this);
}

QuilParser::InstrContext* QuilParser::instr() {
  InstrContext *_localctx = _tracker.createInstance<InstrContext>(_ctx, getState());
  enterRule(_localctx, 4, QuilParser::RuleInstr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(123);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QuilParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(109);
        gate();
        break;
      }

      case QuilParser::MEASURE: {
        enterOuterAlt(_localctx, 2);
        setState(110);
        measure();
        break;
      }

      case QuilParser::LABEL: {
        enterOuterAlt(_localctx, 3);
        setState(111);
        defLabel();
        break;
      }

      case QuilParser::HALT: {
        enterOuterAlt(_localctx, 4);
        setState(112);
        halt();
        break;
      }

      case QuilParser::JUMP: {
        enterOuterAlt(_localctx, 5);
        setState(113);
        jump();
        break;
      }

      case QuilParser::JUMPWHEN: {
        enterOuterAlt(_localctx, 6);
        setState(114);
        jumpWhen();
        break;
      }

      case QuilParser::JUMPUNLESS: {
        enterOuterAlt(_localctx, 7);
        setState(115);
        jumpUnless();
        break;
      }

      case QuilParser::RESET: {
        enterOuterAlt(_localctx, 8);
        setState(116);
        resetState();
        break;
      }

      case QuilParser::WAIT: {
        enterOuterAlt(_localctx, 9);
        setState(117);
        wait();
        break;
      }

      case QuilParser::FALSE:
      case QuilParser::TRUE:
      case QuilParser::NOT: {
        enterOuterAlt(_localctx, 10);
        setState(118);
        classicalUnary();
        break;
      }

      case QuilParser::AND:
      case QuilParser::OR:
      case QuilParser::MOVE:
      case QuilParser::EXCHANGE: {
        enterOuterAlt(_localctx, 11);
        setState(119);
        classicalBinary();
        break;
      }

      case QuilParser::NOP: {
        enterOuterAlt(_localctx, 12);
        setState(120);
        nop();
        break;
      }

      case QuilParser::INCLUDE: {
        enterOuterAlt(_localctx, 13);
        setState(121);
        include();
        break;
      }

      case QuilParser::PRAGMA: {
        enterOuterAlt(_localctx, 14);
        setState(122);
        pragma();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateContext ------------------------------------------------------------------

QuilParser::GateContext::GateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QuilParser::NameContext* QuilParser::GateContext::name() {
  return getRuleContext<QuilParser::NameContext>(0);
}

tree::TerminalNode* QuilParser::GateContext::LPAREN() {
  return getToken(QuilParser::LPAREN, 0);
}

std::vector<QuilParser::ParamContext *> QuilParser::GateContext::param() {
  return getRuleContexts<QuilParser::ParamContext>();
}

QuilParser::ParamContext* QuilParser::GateContext::param(size_t i) {
  return getRuleContext<QuilParser::ParamContext>(i);
}

tree::TerminalNode* QuilParser::GateContext::RPAREN() {
  return getToken(QuilParser::RPAREN, 0);
}

std::vector<QuilParser::QubitContext *> QuilParser::GateContext::qubit() {
  return getRuleContexts<QuilParser::QubitContext>();
}

QuilParser::QubitContext* QuilParser::GateContext::qubit(size_t i) {
  return getRuleContext<QuilParser::QubitContext>(i);
}

std::vector<tree::TerminalNode *> QuilParser::GateContext::COMMA() {
  return getTokens(QuilParser::COMMA);
}

tree::TerminalNode* QuilParser::GateContext::COMMA(size_t i) {
  return getToken(QuilParser::COMMA, i);
}


size_t QuilParser::GateContext::getRuleIndex() const {
  return QuilParser::RuleGate;
}

void QuilParser::GateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGate(this);
}

void QuilParser::GateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGate(this);
}

QuilParser::GateContext* QuilParser::gate() {
  GateContext *_localctx = _tracker.createInstance<GateContext>(_ctx, getState());
  enterRule(_localctx, 6, QuilParser::RuleGate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    name();
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QuilParser::LPAREN) {
      setState(126);
      match(QuilParser::LPAREN);
      setState(127);
      param();
      setState(132);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == QuilParser::COMMA) {
        setState(128);
        match(QuilParser::COMMA);
        setState(129);
        param();
        setState(134);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(135);
      match(QuilParser::RPAREN);
    }
    setState(140); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(139);
      qubit();
      setState(142); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == QuilParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

QuilParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::NameContext::IDENTIFIER() {
  return getToken(QuilParser::IDENTIFIER, 0);
}


size_t QuilParser::NameContext::getRuleIndex() const {
  return QuilParser::RuleName;
}

void QuilParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void QuilParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}

QuilParser::NameContext* QuilParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 8, QuilParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(QuilParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QubitContext ------------------------------------------------------------------

QuilParser::QubitContext::QubitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::QubitContext::INT() {
  return getToken(QuilParser::INT, 0);
}


size_t QuilParser::QubitContext::getRuleIndex() const {
  return QuilParser::RuleQubit;
}

void QuilParser::QubitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQubit(this);
}

void QuilParser::QubitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQubit(this);
}

QuilParser::QubitContext* QuilParser::qubit() {
  QubitContext *_localctx = _tracker.createInstance<QubitContext>(_ctx, getState());
  enterRule(_localctx, 10, QuilParser::RuleQubit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(QuilParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

QuilParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QuilParser::ExpressionContext* QuilParser::ParamContext::expression() {
  return getRuleContext<QuilParser::ExpressionContext>(0);
}


size_t QuilParser::ParamContext::getRuleIndex() const {
  return QuilParser::RuleParam;
}

void QuilParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void QuilParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}

QuilParser::ParamContext* QuilParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 12, QuilParser::RuleParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefGateContext ------------------------------------------------------------------

QuilParser::DefGateContext::DefGateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::DefGateContext::DEFGATE() {
  return getToken(QuilParser::DEFGATE, 0);
}

QuilParser::NameContext* QuilParser::DefGateContext::name() {
  return getRuleContext<QuilParser::NameContext>(0);
}

tree::TerminalNode* QuilParser::DefGateContext::COLON() {
  return getToken(QuilParser::COLON, 0);
}

tree::TerminalNode* QuilParser::DefGateContext::NEWLINE() {
  return getToken(QuilParser::NEWLINE, 0);
}

QuilParser::MatrixContext* QuilParser::DefGateContext::matrix() {
  return getRuleContext<QuilParser::MatrixContext>(0);
}

tree::TerminalNode* QuilParser::DefGateContext::LPAREN() {
  return getToken(QuilParser::LPAREN, 0);
}

std::vector<QuilParser::VariableContext *> QuilParser::DefGateContext::variable() {
  return getRuleContexts<QuilParser::VariableContext>();
}

QuilParser::VariableContext* QuilParser::DefGateContext::variable(size_t i) {
  return getRuleContext<QuilParser::VariableContext>(i);
}

tree::TerminalNode* QuilParser::DefGateContext::RPAREN() {
  return getToken(QuilParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> QuilParser::DefGateContext::COMMA() {
  return getTokens(QuilParser::COMMA);
}

tree::TerminalNode* QuilParser::DefGateContext::COMMA(size_t i) {
  return getToken(QuilParser::COMMA, i);
}


size_t QuilParser::DefGateContext::getRuleIndex() const {
  return QuilParser::RuleDefGate;
}

void QuilParser::DefGateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefGate(this);
}

void QuilParser::DefGateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefGate(this);
}

QuilParser::DefGateContext* QuilParser::defGate() {
  DefGateContext *_localctx = _tracker.createInstance<DefGateContext>(_ctx, getState());
  enterRule(_localctx, 14, QuilParser::RuleDefGate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(QuilParser::DEFGATE);
    setState(151);
    name();
    setState(163);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QuilParser::LPAREN) {
      setState(152);
      match(QuilParser::LPAREN);
      setState(153);
      variable();
      setState(158);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == QuilParser::COMMA) {
        setState(154);
        match(QuilParser::COMMA);
        setState(155);
        variable();
        setState(160);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(161);
      match(QuilParser::RPAREN);
    }
    setState(165);
    match(QuilParser::COLON);
    setState(166);
    match(QuilParser::NEWLINE);
    setState(167);
    matrix();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

QuilParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::VariableContext::PERCENTAGE() {
  return getToken(QuilParser::PERCENTAGE, 0);
}

tree::TerminalNode* QuilParser::VariableContext::IDENTIFIER() {
  return getToken(QuilParser::IDENTIFIER, 0);
}


size_t QuilParser::VariableContext::getRuleIndex() const {
  return QuilParser::RuleVariable;
}

void QuilParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void QuilParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

QuilParser::VariableContext* QuilParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 16, QuilParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    match(QuilParser::PERCENTAGE);
    setState(170);
    match(QuilParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatrixContext ------------------------------------------------------------------

QuilParser::MatrixContext::MatrixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<QuilParser::MatrixRowContext *> QuilParser::MatrixContext::matrixRow() {
  return getRuleContexts<QuilParser::MatrixRowContext>();
}

QuilParser::MatrixRowContext* QuilParser::MatrixContext::matrixRow(size_t i) {
  return getRuleContext<QuilParser::MatrixRowContext>(i);
}

std::vector<tree::TerminalNode *> QuilParser::MatrixContext::NEWLINE() {
  return getTokens(QuilParser::NEWLINE);
}

tree::TerminalNode* QuilParser::MatrixContext::NEWLINE(size_t i) {
  return getToken(QuilParser::NEWLINE, i);
}


size_t QuilParser::MatrixContext::getRuleIndex() const {
  return QuilParser::RuleMatrix;
}

void QuilParser::MatrixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatrix(this);
}

void QuilParser::MatrixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatrix(this);
}

QuilParser::MatrixContext* QuilParser::matrix() {
  MatrixContext *_localctx = _tracker.createInstance<MatrixContext>(_ctx, getState());
  enterRule(_localctx, 18, QuilParser::RuleMatrix);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(177);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(172);
        matrixRow();
        setState(173);
        match(QuilParser::NEWLINE); 
      }
      setState(179);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
    setState(180);
    matrixRow();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatrixRowContext ------------------------------------------------------------------

QuilParser::MatrixRowContext::MatrixRowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::MatrixRowContext::TAB() {
  return getToken(QuilParser::TAB, 0);
}

std::vector<QuilParser::ExpressionContext *> QuilParser::MatrixRowContext::expression() {
  return getRuleContexts<QuilParser::ExpressionContext>();
}

QuilParser::ExpressionContext* QuilParser::MatrixRowContext::expression(size_t i) {
  return getRuleContext<QuilParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> QuilParser::MatrixRowContext::COMMA() {
  return getTokens(QuilParser::COMMA);
}

tree::TerminalNode* QuilParser::MatrixRowContext::COMMA(size_t i) {
  return getToken(QuilParser::COMMA, i);
}


size_t QuilParser::MatrixRowContext::getRuleIndex() const {
  return QuilParser::RuleMatrixRow;
}

void QuilParser::MatrixRowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatrixRow(this);
}

void QuilParser::MatrixRowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatrixRow(this);
}

QuilParser::MatrixRowContext* QuilParser::matrixRow() {
  MatrixRowContext *_localctx = _tracker.createInstance<MatrixRowContext>(_ctx, getState());
  enterRule(_localctx, 20, QuilParser::RuleMatrixRow);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(QuilParser::TAB);
    setState(183);
    expression(0);
    setState(188);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == QuilParser::COMMA) {
      setState(184);
      match(QuilParser::COMMA);
      setState(185);
      expression(0);
      setState(190);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefCircuitContext ------------------------------------------------------------------

QuilParser::DefCircuitContext::DefCircuitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::DefCircuitContext::DEFCIRCUIT() {
  return getToken(QuilParser::DEFCIRCUIT, 0);
}

QuilParser::NameContext* QuilParser::DefCircuitContext::name() {
  return getRuleContext<QuilParser::NameContext>(0);
}

tree::TerminalNode* QuilParser::DefCircuitContext::COLON() {
  return getToken(QuilParser::COLON, 0);
}

tree::TerminalNode* QuilParser::DefCircuitContext::NEWLINE() {
  return getToken(QuilParser::NEWLINE, 0);
}

QuilParser::CircuitContext* QuilParser::DefCircuitContext::circuit() {
  return getRuleContext<QuilParser::CircuitContext>(0);
}

tree::TerminalNode* QuilParser::DefCircuitContext::LPAREN() {
  return getToken(QuilParser::LPAREN, 0);
}

std::vector<QuilParser::VariableContext *> QuilParser::DefCircuitContext::variable() {
  return getRuleContexts<QuilParser::VariableContext>();
}

QuilParser::VariableContext* QuilParser::DefCircuitContext::variable(size_t i) {
  return getRuleContext<QuilParser::VariableContext>(i);
}

tree::TerminalNode* QuilParser::DefCircuitContext::RPAREN() {
  return getToken(QuilParser::RPAREN, 0);
}

std::vector<QuilParser::QubitVariableContext *> QuilParser::DefCircuitContext::qubitVariable() {
  return getRuleContexts<QuilParser::QubitVariableContext>();
}

QuilParser::QubitVariableContext* QuilParser::DefCircuitContext::qubitVariable(size_t i) {
  return getRuleContext<QuilParser::QubitVariableContext>(i);
}

std::vector<tree::TerminalNode *> QuilParser::DefCircuitContext::COMMA() {
  return getTokens(QuilParser::COMMA);
}

tree::TerminalNode* QuilParser::DefCircuitContext::COMMA(size_t i) {
  return getToken(QuilParser::COMMA, i);
}


size_t QuilParser::DefCircuitContext::getRuleIndex() const {
  return QuilParser::RuleDefCircuit;
}

void QuilParser::DefCircuitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefCircuit(this);
}

void QuilParser::DefCircuitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefCircuit(this);
}

QuilParser::DefCircuitContext* QuilParser::defCircuit() {
  DefCircuitContext *_localctx = _tracker.createInstance<DefCircuitContext>(_ctx, getState());
  enterRule(_localctx, 22, QuilParser::RuleDefCircuit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    match(QuilParser::DEFCIRCUIT);
    setState(192);
    name();
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QuilParser::LPAREN) {
      setState(193);
      match(QuilParser::LPAREN);
      setState(194);
      variable();
      setState(199);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == QuilParser::COMMA) {
        setState(195);
        match(QuilParser::COMMA);
        setState(196);
        variable();
        setState(201);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(202);
      match(QuilParser::RPAREN);
    }
    setState(209);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == QuilParser::IDENTIFIER) {
      setState(206);
      qubitVariable();
      setState(211);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(212);
    match(QuilParser::COLON);
    setState(213);
    match(QuilParser::NEWLINE);
    setState(214);
    circuit();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QubitVariableContext ------------------------------------------------------------------

QuilParser::QubitVariableContext::QubitVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::QubitVariableContext::IDENTIFIER() {
  return getToken(QuilParser::IDENTIFIER, 0);
}


size_t QuilParser::QubitVariableContext::getRuleIndex() const {
  return QuilParser::RuleQubitVariable;
}

void QuilParser::QubitVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQubitVariable(this);
}

void QuilParser::QubitVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQubitVariable(this);
}

QuilParser::QubitVariableContext* QuilParser::qubitVariable() {
  QubitVariableContext *_localctx = _tracker.createInstance<QubitVariableContext>(_ctx, getState());
  enterRule(_localctx, 24, QuilParser::RuleQubitVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    match(QuilParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CircuitQubitContext ------------------------------------------------------------------

QuilParser::CircuitQubitContext::CircuitQubitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QuilParser::QubitContext* QuilParser::CircuitQubitContext::qubit() {
  return getRuleContext<QuilParser::QubitContext>(0);
}

QuilParser::QubitVariableContext* QuilParser::CircuitQubitContext::qubitVariable() {
  return getRuleContext<QuilParser::QubitVariableContext>(0);
}


size_t QuilParser::CircuitQubitContext::getRuleIndex() const {
  return QuilParser::RuleCircuitQubit;
}

void QuilParser::CircuitQubitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCircuitQubit(this);
}

void QuilParser::CircuitQubitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCircuitQubit(this);
}

QuilParser::CircuitQubitContext* QuilParser::circuitQubit() {
  CircuitQubitContext *_localctx = _tracker.createInstance<CircuitQubitContext>(_ctx, getState());
  enterRule(_localctx, 26, QuilParser::RuleCircuitQubit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(220);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QuilParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(218);
        qubit();
        break;
      }

      case QuilParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(219);
        qubitVariable();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CircuitGateContext ------------------------------------------------------------------

QuilParser::CircuitGateContext::CircuitGateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QuilParser::NameContext* QuilParser::CircuitGateContext::name() {
  return getRuleContext<QuilParser::NameContext>(0);
}

tree::TerminalNode* QuilParser::CircuitGateContext::LPAREN() {
  return getToken(QuilParser::LPAREN, 0);
}

std::vector<QuilParser::ParamContext *> QuilParser::CircuitGateContext::param() {
  return getRuleContexts<QuilParser::ParamContext>();
}

QuilParser::ParamContext* QuilParser::CircuitGateContext::param(size_t i) {
  return getRuleContext<QuilParser::ParamContext>(i);
}

tree::TerminalNode* QuilParser::CircuitGateContext::RPAREN() {
  return getToken(QuilParser::RPAREN, 0);
}

std::vector<QuilParser::CircuitQubitContext *> QuilParser::CircuitGateContext::circuitQubit() {
  return getRuleContexts<QuilParser::CircuitQubitContext>();
}

QuilParser::CircuitQubitContext* QuilParser::CircuitGateContext::circuitQubit(size_t i) {
  return getRuleContext<QuilParser::CircuitQubitContext>(i);
}

std::vector<tree::TerminalNode *> QuilParser::CircuitGateContext::COMMA() {
  return getTokens(QuilParser::COMMA);
}

tree::TerminalNode* QuilParser::CircuitGateContext::COMMA(size_t i) {
  return getToken(QuilParser::COMMA, i);
}


size_t QuilParser::CircuitGateContext::getRuleIndex() const {
  return QuilParser::RuleCircuitGate;
}

void QuilParser::CircuitGateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCircuitGate(this);
}

void QuilParser::CircuitGateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCircuitGate(this);
}

QuilParser::CircuitGateContext* QuilParser::circuitGate() {
  CircuitGateContext *_localctx = _tracker.createInstance<CircuitGateContext>(_ctx, getState());
  enterRule(_localctx, 28, QuilParser::RuleCircuitGate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    name();
    setState(234);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QuilParser::LPAREN) {
      setState(223);
      match(QuilParser::LPAREN);
      setState(224);
      param();
      setState(229);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == QuilParser::COMMA) {
        setState(225);
        match(QuilParser::COMMA);
        setState(226);
        param();
        setState(231);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(232);
      match(QuilParser::RPAREN);
    }
    setState(237); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(236);
      circuitQubit();
      setState(239); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == QuilParser::IDENTIFIER

    || _la == QuilParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CircuitInstrContext ------------------------------------------------------------------

QuilParser::CircuitInstrContext::CircuitInstrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QuilParser::CircuitGateContext* QuilParser::CircuitInstrContext::circuitGate() {
  return getRuleContext<QuilParser::CircuitGateContext>(0);
}

QuilParser::InstrContext* QuilParser::CircuitInstrContext::instr() {
  return getRuleContext<QuilParser::InstrContext>(0);
}


size_t QuilParser::CircuitInstrContext::getRuleIndex() const {
  return QuilParser::RuleCircuitInstr;
}

void QuilParser::CircuitInstrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCircuitInstr(this);
}

void QuilParser::CircuitInstrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCircuitInstr(this);
}

QuilParser::CircuitInstrContext* QuilParser::circuitInstr() {
  CircuitInstrContext *_localctx = _tracker.createInstance<CircuitInstrContext>(_ctx, getState());
  enterRule(_localctx, 30, QuilParser::RuleCircuitInstr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(243);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(241);
      circuitGate();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(242);
      instr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CircuitContext ------------------------------------------------------------------

QuilParser::CircuitContext::CircuitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> QuilParser::CircuitContext::TAB() {
  return getTokens(QuilParser::TAB);
}

tree::TerminalNode* QuilParser::CircuitContext::TAB(size_t i) {
  return getToken(QuilParser::TAB, i);
}

std::vector<QuilParser::CircuitInstrContext *> QuilParser::CircuitContext::circuitInstr() {
  return getRuleContexts<QuilParser::CircuitInstrContext>();
}

QuilParser::CircuitInstrContext* QuilParser::CircuitContext::circuitInstr(size_t i) {
  return getRuleContext<QuilParser::CircuitInstrContext>(i);
}

std::vector<tree::TerminalNode *> QuilParser::CircuitContext::NEWLINE() {
  return getTokens(QuilParser::NEWLINE);
}

tree::TerminalNode* QuilParser::CircuitContext::NEWLINE(size_t i) {
  return getToken(QuilParser::NEWLINE, i);
}


size_t QuilParser::CircuitContext::getRuleIndex() const {
  return QuilParser::RuleCircuit;
}

void QuilParser::CircuitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCircuit(this);
}

void QuilParser::CircuitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCircuit(this);
}

QuilParser::CircuitContext* QuilParser::circuit() {
  CircuitContext *_localctx = _tracker.createInstance<CircuitContext>(_ctx, getState());
  enterRule(_localctx, 32, QuilParser::RuleCircuit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(251);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(245);
        match(QuilParser::TAB);
        setState(246);
        circuitInstr();
        setState(247);
        match(QuilParser::NEWLINE); 
      }
      setState(253);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
    setState(254);
    match(QuilParser::TAB);
    setState(255);
    circuitInstr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeasureContext ------------------------------------------------------------------

QuilParser::MeasureContext::MeasureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::MeasureContext::MEASURE() {
  return getToken(QuilParser::MEASURE, 0);
}

QuilParser::QubitContext* QuilParser::MeasureContext::qubit() {
  return getRuleContext<QuilParser::QubitContext>(0);
}

QuilParser::AddrContext* QuilParser::MeasureContext::addr() {
  return getRuleContext<QuilParser::AddrContext>(0);
}


size_t QuilParser::MeasureContext::getRuleIndex() const {
  return QuilParser::RuleMeasure;
}

void QuilParser::MeasureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMeasure(this);
}

void QuilParser::MeasureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMeasure(this);
}

QuilParser::MeasureContext* QuilParser::measure() {
  MeasureContext *_localctx = _tracker.createInstance<MeasureContext>(_ctx, getState());
  enterRule(_localctx, 34, QuilParser::RuleMeasure);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(QuilParser::MEASURE);
    setState(258);
    qubit();
    setState(260);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QuilParser::LBRACKET) {
      setState(259);
      addr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddrContext ------------------------------------------------------------------

QuilParser::AddrContext::AddrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::AddrContext::LBRACKET() {
  return getToken(QuilParser::LBRACKET, 0);
}

QuilParser::ClassicalBitContext* QuilParser::AddrContext::classicalBit() {
  return getRuleContext<QuilParser::ClassicalBitContext>(0);
}

tree::TerminalNode* QuilParser::AddrContext::RBRACKET() {
  return getToken(QuilParser::RBRACKET, 0);
}


size_t QuilParser::AddrContext::getRuleIndex() const {
  return QuilParser::RuleAddr;
}

void QuilParser::AddrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddr(this);
}

void QuilParser::AddrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddr(this);
}

QuilParser::AddrContext* QuilParser::addr() {
  AddrContext *_localctx = _tracker.createInstance<AddrContext>(_ctx, getState());
  enterRule(_localctx, 36, QuilParser::RuleAddr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(QuilParser::LBRACKET);
    setState(263);
    classicalBit();
    setState(264);
    match(QuilParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalBitContext ------------------------------------------------------------------

QuilParser::ClassicalBitContext::ClassicalBitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> QuilParser::ClassicalBitContext::INT() {
  return getTokens(QuilParser::INT);
}

tree::TerminalNode* QuilParser::ClassicalBitContext::INT(size_t i) {
  return getToken(QuilParser::INT, i);
}


size_t QuilParser::ClassicalBitContext::getRuleIndex() const {
  return QuilParser::RuleClassicalBit;
}

void QuilParser::ClassicalBitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassicalBit(this);
}

void QuilParser::ClassicalBitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassicalBit(this);
}

QuilParser::ClassicalBitContext* QuilParser::classicalBit() {
  ClassicalBitContext *_localctx = _tracker.createInstance<ClassicalBitContext>(_ctx, getState());
  enterRule(_localctx, 38, QuilParser::RuleClassicalBit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(266);
      match(QuilParser::INT);
      setState(269); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == QuilParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefLabelContext ------------------------------------------------------------------

QuilParser::DefLabelContext::DefLabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::DefLabelContext::LABEL() {
  return getToken(QuilParser::LABEL, 0);
}

QuilParser::LabelContext* QuilParser::DefLabelContext::label() {
  return getRuleContext<QuilParser::LabelContext>(0);
}


size_t QuilParser::DefLabelContext::getRuleIndex() const {
  return QuilParser::RuleDefLabel;
}

void QuilParser::DefLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefLabel(this);
}

void QuilParser::DefLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefLabel(this);
}

QuilParser::DefLabelContext* QuilParser::defLabel() {
  DefLabelContext *_localctx = _tracker.createInstance<DefLabelContext>(_ctx, getState());
  enterRule(_localctx, 40, QuilParser::RuleDefLabel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    match(QuilParser::LABEL);
    setState(272);
    label();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelContext ------------------------------------------------------------------

QuilParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::LabelContext::AT() {
  return getToken(QuilParser::AT, 0);
}

tree::TerminalNode* QuilParser::LabelContext::IDENTIFIER() {
  return getToken(QuilParser::IDENTIFIER, 0);
}


size_t QuilParser::LabelContext::getRuleIndex() const {
  return QuilParser::RuleLabel;
}

void QuilParser::LabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel(this);
}

void QuilParser::LabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel(this);
}

QuilParser::LabelContext* QuilParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 42, QuilParser::RuleLabel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    match(QuilParser::AT);
    setState(275);
    match(QuilParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HaltContext ------------------------------------------------------------------

QuilParser::HaltContext::HaltContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::HaltContext::HALT() {
  return getToken(QuilParser::HALT, 0);
}


size_t QuilParser::HaltContext::getRuleIndex() const {
  return QuilParser::RuleHalt;
}

void QuilParser::HaltContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHalt(this);
}

void QuilParser::HaltContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHalt(this);
}

QuilParser::HaltContext* QuilParser::halt() {
  HaltContext *_localctx = _tracker.createInstance<HaltContext>(_ctx, getState());
  enterRule(_localctx, 44, QuilParser::RuleHalt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    match(QuilParser::HALT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JumpContext ------------------------------------------------------------------

QuilParser::JumpContext::JumpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::JumpContext::JUMP() {
  return getToken(QuilParser::JUMP, 0);
}

QuilParser::LabelContext* QuilParser::JumpContext::label() {
  return getRuleContext<QuilParser::LabelContext>(0);
}


size_t QuilParser::JumpContext::getRuleIndex() const {
  return QuilParser::RuleJump;
}

void QuilParser::JumpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJump(this);
}

void QuilParser::JumpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJump(this);
}

QuilParser::JumpContext* QuilParser::jump() {
  JumpContext *_localctx = _tracker.createInstance<JumpContext>(_ctx, getState());
  enterRule(_localctx, 46, QuilParser::RuleJump);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    match(QuilParser::JUMP);
    setState(280);
    label();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JumpWhenContext ------------------------------------------------------------------

QuilParser::JumpWhenContext::JumpWhenContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::JumpWhenContext::JUMPWHEN() {
  return getToken(QuilParser::JUMPWHEN, 0);
}

QuilParser::LabelContext* QuilParser::JumpWhenContext::label() {
  return getRuleContext<QuilParser::LabelContext>(0);
}

QuilParser::AddrContext* QuilParser::JumpWhenContext::addr() {
  return getRuleContext<QuilParser::AddrContext>(0);
}


size_t QuilParser::JumpWhenContext::getRuleIndex() const {
  return QuilParser::RuleJumpWhen;
}

void QuilParser::JumpWhenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJumpWhen(this);
}

void QuilParser::JumpWhenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJumpWhen(this);
}

QuilParser::JumpWhenContext* QuilParser::jumpWhen() {
  JumpWhenContext *_localctx = _tracker.createInstance<JumpWhenContext>(_ctx, getState());
  enterRule(_localctx, 48, QuilParser::RuleJumpWhen);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    match(QuilParser::JUMPWHEN);
    setState(283);
    label();
    setState(284);
    addr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JumpUnlessContext ------------------------------------------------------------------

QuilParser::JumpUnlessContext::JumpUnlessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::JumpUnlessContext::JUMPUNLESS() {
  return getToken(QuilParser::JUMPUNLESS, 0);
}

QuilParser::LabelContext* QuilParser::JumpUnlessContext::label() {
  return getRuleContext<QuilParser::LabelContext>(0);
}

QuilParser::AddrContext* QuilParser::JumpUnlessContext::addr() {
  return getRuleContext<QuilParser::AddrContext>(0);
}


size_t QuilParser::JumpUnlessContext::getRuleIndex() const {
  return QuilParser::RuleJumpUnless;
}

void QuilParser::JumpUnlessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJumpUnless(this);
}

void QuilParser::JumpUnlessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJumpUnless(this);
}

QuilParser::JumpUnlessContext* QuilParser::jumpUnless() {
  JumpUnlessContext *_localctx = _tracker.createInstance<JumpUnlessContext>(_ctx, getState());
  enterRule(_localctx, 50, QuilParser::RuleJumpUnless);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    match(QuilParser::JUMPUNLESS);
    setState(287);
    label();
    setState(288);
    addr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResetStateContext ------------------------------------------------------------------

QuilParser::ResetStateContext::ResetStateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::ResetStateContext::RESET() {
  return getToken(QuilParser::RESET, 0);
}


size_t QuilParser::ResetStateContext::getRuleIndex() const {
  return QuilParser::RuleResetState;
}

void QuilParser::ResetStateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResetState(this);
}

void QuilParser::ResetStateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResetState(this);
}

QuilParser::ResetStateContext* QuilParser::resetState() {
  ResetStateContext *_localctx = _tracker.createInstance<ResetStateContext>(_ctx, getState());
  enterRule(_localctx, 52, QuilParser::RuleResetState);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    match(QuilParser::RESET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WaitContext ------------------------------------------------------------------

QuilParser::WaitContext::WaitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::WaitContext::WAIT() {
  return getToken(QuilParser::WAIT, 0);
}


size_t QuilParser::WaitContext::getRuleIndex() const {
  return QuilParser::RuleWait;
}

void QuilParser::WaitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWait(this);
}

void QuilParser::WaitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWait(this);
}

QuilParser::WaitContext* QuilParser::wait() {
  WaitContext *_localctx = _tracker.createInstance<WaitContext>(_ctx, getState());
  enterRule(_localctx, 54, QuilParser::RuleWait);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    match(QuilParser::WAIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalUnaryContext ------------------------------------------------------------------

QuilParser::ClassicalUnaryContext::ClassicalUnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QuilParser::AddrContext* QuilParser::ClassicalUnaryContext::addr() {
  return getRuleContext<QuilParser::AddrContext>(0);
}

tree::TerminalNode* QuilParser::ClassicalUnaryContext::TRUE() {
  return getToken(QuilParser::TRUE, 0);
}

tree::TerminalNode* QuilParser::ClassicalUnaryContext::FALSE() {
  return getToken(QuilParser::FALSE, 0);
}

tree::TerminalNode* QuilParser::ClassicalUnaryContext::NOT() {
  return getToken(QuilParser::NOT, 0);
}


size_t QuilParser::ClassicalUnaryContext::getRuleIndex() const {
  return QuilParser::RuleClassicalUnary;
}

void QuilParser::ClassicalUnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassicalUnary(this);
}

void QuilParser::ClassicalUnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassicalUnary(this);
}

QuilParser::ClassicalUnaryContext* QuilParser::classicalUnary() {
  ClassicalUnaryContext *_localctx = _tracker.createInstance<ClassicalUnaryContext>(_ctx, getState());
  enterRule(_localctx, 56, QuilParser::RuleClassicalUnary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QuilParser::FALSE)
      | (1ULL << QuilParser::TRUE)
      | (1ULL << QuilParser::NOT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(295);
    addr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalBinaryContext ------------------------------------------------------------------

QuilParser::ClassicalBinaryContext::ClassicalBinaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<QuilParser::AddrContext *> QuilParser::ClassicalBinaryContext::addr() {
  return getRuleContexts<QuilParser::AddrContext>();
}

QuilParser::AddrContext* QuilParser::ClassicalBinaryContext::addr(size_t i) {
  return getRuleContext<QuilParser::AddrContext>(i);
}

tree::TerminalNode* QuilParser::ClassicalBinaryContext::AND() {
  return getToken(QuilParser::AND, 0);
}

tree::TerminalNode* QuilParser::ClassicalBinaryContext::OR() {
  return getToken(QuilParser::OR, 0);
}

tree::TerminalNode* QuilParser::ClassicalBinaryContext::MOVE() {
  return getToken(QuilParser::MOVE, 0);
}

tree::TerminalNode* QuilParser::ClassicalBinaryContext::EXCHANGE() {
  return getToken(QuilParser::EXCHANGE, 0);
}


size_t QuilParser::ClassicalBinaryContext::getRuleIndex() const {
  return QuilParser::RuleClassicalBinary;
}

void QuilParser::ClassicalBinaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassicalBinary(this);
}

void QuilParser::ClassicalBinaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassicalBinary(this);
}

QuilParser::ClassicalBinaryContext* QuilParser::classicalBinary() {
  ClassicalBinaryContext *_localctx = _tracker.createInstance<ClassicalBinaryContext>(_ctx, getState());
  enterRule(_localctx, 58, QuilParser::RuleClassicalBinary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QuilParser::AND)
      | (1ULL << QuilParser::OR)
      | (1ULL << QuilParser::MOVE)
      | (1ULL << QuilParser::EXCHANGE))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(298);
    addr();
    setState(299);
    addr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NopContext ------------------------------------------------------------------

QuilParser::NopContext::NopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::NopContext::NOP() {
  return getToken(QuilParser::NOP, 0);
}


size_t QuilParser::NopContext::getRuleIndex() const {
  return QuilParser::RuleNop;
}

void QuilParser::NopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNop(this);
}

void QuilParser::NopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNop(this);
}

QuilParser::NopContext* QuilParser::nop() {
  NopContext *_localctx = _tracker.createInstance<NopContext>(_ctx, getState());
  enterRule(_localctx, 60, QuilParser::RuleNop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    match(QuilParser::NOP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

QuilParser::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::IncludeContext::INCLUDE() {
  return getToken(QuilParser::INCLUDE, 0);
}

tree::TerminalNode* QuilParser::IncludeContext::STRING() {
  return getToken(QuilParser::STRING, 0);
}


size_t QuilParser::IncludeContext::getRuleIndex() const {
  return QuilParser::RuleInclude;
}

void QuilParser::IncludeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInclude(this);
}

void QuilParser::IncludeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInclude(this);
}

QuilParser::IncludeContext* QuilParser::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 62, QuilParser::RuleInclude);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    match(QuilParser::INCLUDE);
    setState(304);
    match(QuilParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PragmaContext ------------------------------------------------------------------

QuilParser::PragmaContext::PragmaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::PragmaContext::PRAGMA() {
  return getToken(QuilParser::PRAGMA, 0);
}

tree::TerminalNode* QuilParser::PragmaContext::IDENTIFIER() {
  return getToken(QuilParser::IDENTIFIER, 0);
}

std::vector<QuilParser::Pragma_nameContext *> QuilParser::PragmaContext::pragma_name() {
  return getRuleContexts<QuilParser::Pragma_nameContext>();
}

QuilParser::Pragma_nameContext* QuilParser::PragmaContext::pragma_name(size_t i) {
  return getRuleContext<QuilParser::Pragma_nameContext>(i);
}

tree::TerminalNode* QuilParser::PragmaContext::STRING() {
  return getToken(QuilParser::STRING, 0);
}


size_t QuilParser::PragmaContext::getRuleIndex() const {
  return QuilParser::RulePragma;
}

void QuilParser::PragmaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma(this);
}

void QuilParser::PragmaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma(this);
}

QuilParser::PragmaContext* QuilParser::pragma() {
  PragmaContext *_localctx = _tracker.createInstance<PragmaContext>(_ctx, getState());
  enterRule(_localctx, 64, QuilParser::RulePragma);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    match(QuilParser::PRAGMA);
    setState(307);
    match(QuilParser::IDENTIFIER);
    setState(311);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == QuilParser::IDENTIFIER

    || _la == QuilParser::INT) {
      setState(308);
      pragma_name();
      setState(313);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(315);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QuilParser::STRING) {
      setState(314);
      match(QuilParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pragma_nameContext ------------------------------------------------------------------

QuilParser::Pragma_nameContext::Pragma_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::Pragma_nameContext::IDENTIFIER() {
  return getToken(QuilParser::IDENTIFIER, 0);
}

tree::TerminalNode* QuilParser::Pragma_nameContext::INT() {
  return getToken(QuilParser::INT, 0);
}


size_t QuilParser::Pragma_nameContext::getRuleIndex() const {
  return QuilParser::RulePragma_name;
}

void QuilParser::Pragma_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma_name(this);
}

void QuilParser::Pragma_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma_name(this);
}

QuilParser::Pragma_nameContext* QuilParser::pragma_name() {
  Pragma_nameContext *_localctx = _tracker.createInstance<Pragma_nameContext>(_ctx, getState());
  enterRule(_localctx, 66, QuilParser::RulePragma_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(317);
    _la = _input->LA(1);
    if (!(_la == QuilParser::IDENTIFIER

    || _la == QuilParser::INT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

QuilParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t QuilParser::ExpressionContext::getRuleIndex() const {
  return QuilParser::RuleExpression;
}

void QuilParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SegmentExpContext ------------------------------------------------------------------

QuilParser::SegmentContext* QuilParser::SegmentExpContext::segment() {
  return getRuleContext<QuilParser::SegmentContext>(0);
}

QuilParser::SegmentExpContext::SegmentExpContext(ExpressionContext *ctx) { copyFrom(ctx); }

void QuilParser::SegmentExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSegmentExp(this);
}
void QuilParser::SegmentExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSegmentExp(this);
}
//----------------- NumberExpContext ------------------------------------------------------------------

QuilParser::NumberContext* QuilParser::NumberExpContext::number() {
  return getRuleContext<QuilParser::NumberContext>(0);
}

QuilParser::NumberExpContext::NumberExpContext(ExpressionContext *ctx) { copyFrom(ctx); }

void QuilParser::NumberExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberExp(this);
}
void QuilParser::NumberExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberExp(this);
}
//----------------- PowerExpContext ------------------------------------------------------------------

std::vector<QuilParser::ExpressionContext *> QuilParser::PowerExpContext::expression() {
  return getRuleContexts<QuilParser::ExpressionContext>();
}

QuilParser::ExpressionContext* QuilParser::PowerExpContext::expression(size_t i) {
  return getRuleContext<QuilParser::ExpressionContext>(i);
}

tree::TerminalNode* QuilParser::PowerExpContext::POWER() {
  return getToken(QuilParser::POWER, 0);
}

QuilParser::PowerExpContext::PowerExpContext(ExpressionContext *ctx) { copyFrom(ctx); }

void QuilParser::PowerExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPowerExp(this);
}
void QuilParser::PowerExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPowerExp(this);
}
//----------------- MulDivExpContext ------------------------------------------------------------------

std::vector<QuilParser::ExpressionContext *> QuilParser::MulDivExpContext::expression() {
  return getRuleContexts<QuilParser::ExpressionContext>();
}

QuilParser::ExpressionContext* QuilParser::MulDivExpContext::expression(size_t i) {
  return getRuleContext<QuilParser::ExpressionContext>(i);
}

tree::TerminalNode* QuilParser::MulDivExpContext::TIMES() {
  return getToken(QuilParser::TIMES, 0);
}

tree::TerminalNode* QuilParser::MulDivExpContext::DIVIDE() {
  return getToken(QuilParser::DIVIDE, 0);
}

QuilParser::MulDivExpContext::MulDivExpContext(ExpressionContext *ctx) { copyFrom(ctx); }

void QuilParser::MulDivExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulDivExp(this);
}
void QuilParser::MulDivExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulDivExp(this);
}
//----------------- ParenthesisExpContext ------------------------------------------------------------------

tree::TerminalNode* QuilParser::ParenthesisExpContext::LPAREN() {
  return getToken(QuilParser::LPAREN, 0);
}

QuilParser::ExpressionContext* QuilParser::ParenthesisExpContext::expression() {
  return getRuleContext<QuilParser::ExpressionContext>(0);
}

tree::TerminalNode* QuilParser::ParenthesisExpContext::RPAREN() {
  return getToken(QuilParser::RPAREN, 0);
}

QuilParser::ParenthesisExpContext::ParenthesisExpContext(ExpressionContext *ctx) { copyFrom(ctx); }

void QuilParser::ParenthesisExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesisExp(this);
}
void QuilParser::ParenthesisExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesisExp(this);
}
//----------------- VariableExpContext ------------------------------------------------------------------

QuilParser::VariableContext* QuilParser::VariableExpContext::variable() {
  return getRuleContext<QuilParser::VariableContext>(0);
}

QuilParser::VariableExpContext::VariableExpContext(ExpressionContext *ctx) { copyFrom(ctx); }

void QuilParser::VariableExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableExp(this);
}
void QuilParser::VariableExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableExp(this);
}
//----------------- SignedExpContext ------------------------------------------------------------------

QuilParser::SignContext* QuilParser::SignedExpContext::sign() {
  return getRuleContext<QuilParser::SignContext>(0);
}

QuilParser::ExpressionContext* QuilParser::SignedExpContext::expression() {
  return getRuleContext<QuilParser::ExpressionContext>(0);
}

QuilParser::SignedExpContext::SignedExpContext(ExpressionContext *ctx) { copyFrom(ctx); }

void QuilParser::SignedExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignedExp(this);
}
void QuilParser::SignedExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignedExp(this);
}
//----------------- AddSubExpContext ------------------------------------------------------------------

std::vector<QuilParser::ExpressionContext *> QuilParser::AddSubExpContext::expression() {
  return getRuleContexts<QuilParser::ExpressionContext>();
}

QuilParser::ExpressionContext* QuilParser::AddSubExpContext::expression(size_t i) {
  return getRuleContext<QuilParser::ExpressionContext>(i);
}

tree::TerminalNode* QuilParser::AddSubExpContext::PLUS() {
  return getToken(QuilParser::PLUS, 0);
}

tree::TerminalNode* QuilParser::AddSubExpContext::MINUS() {
  return getToken(QuilParser::MINUS, 0);
}

QuilParser::AddSubExpContext::AddSubExpContext(ExpressionContext *ctx) { copyFrom(ctx); }

void QuilParser::AddSubExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddSubExp(this);
}
void QuilParser::AddSubExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddSubExp(this);
}
//----------------- FunctionExpContext ------------------------------------------------------------------

QuilParser::FunctionContext* QuilParser::FunctionExpContext::function() {
  return getRuleContext<QuilParser::FunctionContext>(0);
}

tree::TerminalNode* QuilParser::FunctionExpContext::LPAREN() {
  return getToken(QuilParser::LPAREN, 0);
}

QuilParser::ExpressionContext* QuilParser::FunctionExpContext::expression() {
  return getRuleContext<QuilParser::ExpressionContext>(0);
}

tree::TerminalNode* QuilParser::FunctionExpContext::RPAREN() {
  return getToken(QuilParser::RPAREN, 0);
}

QuilParser::FunctionExpContext::FunctionExpContext(ExpressionContext *ctx) { copyFrom(ctx); }

void QuilParser::FunctionExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionExp(this);
}
void QuilParser::FunctionExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionExp(this);
}

QuilParser::ExpressionContext* QuilParser::expression() {
   return expression(0);
}

QuilParser::ExpressionContext* QuilParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  QuilParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  QuilParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, QuilParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(335);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QuilParser::LPAREN: {
        _localctx = _tracker.createInstance<ParenthesisExpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(320);
        match(QuilParser::LPAREN);
        setState(321);
        expression(0);
        setState(322);
        match(QuilParser::RPAREN);
        break;
      }

      case QuilParser::PLUS:
      case QuilParser::MINUS: {
        _localctx = _tracker.createInstance<SignedExpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(324);
        sign();
        setState(325);
        expression(8);
        break;
      }

      case QuilParser::SIN:
      case QuilParser::COS:
      case QuilParser::SQRT:
      case QuilParser::EXP:
      case QuilParser::CIS: {
        _localctx = _tracker.createInstance<FunctionExpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(327);
        function();
        setState(328);
        match(QuilParser::LPAREN);
        setState(329);
        expression(0);
        setState(330);
        match(QuilParser::RPAREN);
        break;
      }

      case QuilParser::LBRACKET: {
        _localctx = _tracker.createInstance<SegmentExpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(332);
        segment();
        break;
      }

      case QuilParser::PI:
      case QuilParser::I:
      case QuilParser::INT:
      case QuilParser::FLOAT: {
        _localctx = _tracker.createInstance<NumberExpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(333);
        number();
        break;
      }

      case QuilParser::PERCENTAGE: {
        _localctx = _tracker.createInstance<VariableExpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(334);
        variable();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(348);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(346);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<PowerExpContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(337);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(338);
          match(QuilParser::POWER);
          setState(339);
          expression(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MulDivExpContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(340);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(341);
          _la = _input->LA(1);
          if (!(_la == QuilParser::TIMES

          || _la == QuilParser::DIVIDE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(342);
          expression(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddSubExpContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(343);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(344);
          _la = _input->LA(1);
          if (!(_la == QuilParser::PLUS

          || _la == QuilParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(345);
          expression(6);
          break;
        }

        } 
      }
      setState(350);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SegmentContext ------------------------------------------------------------------

QuilParser::SegmentContext::SegmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::SegmentContext::LBRACKET() {
  return getToken(QuilParser::LBRACKET, 0);
}

std::vector<tree::TerminalNode *> QuilParser::SegmentContext::INT() {
  return getTokens(QuilParser::INT);
}

tree::TerminalNode* QuilParser::SegmentContext::INT(size_t i) {
  return getToken(QuilParser::INT, i);
}

tree::TerminalNode* QuilParser::SegmentContext::MINUS() {
  return getToken(QuilParser::MINUS, 0);
}

tree::TerminalNode* QuilParser::SegmentContext::RBRACKET() {
  return getToken(QuilParser::RBRACKET, 0);
}


size_t QuilParser::SegmentContext::getRuleIndex() const {
  return QuilParser::RuleSegment;
}

void QuilParser::SegmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSegment(this);
}

void QuilParser::SegmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSegment(this);
}

QuilParser::SegmentContext* QuilParser::segment() {
  SegmentContext *_localctx = _tracker.createInstance<SegmentContext>(_ctx, getState());
  enterRule(_localctx, 70, QuilParser::RuleSegment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    match(QuilParser::LBRACKET);
    setState(352);
    match(QuilParser::INT);
    setState(353);
    match(QuilParser::MINUS);
    setState(354);
    match(QuilParser::INT);
    setState(355);
    match(QuilParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

QuilParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::FunctionContext::SIN() {
  return getToken(QuilParser::SIN, 0);
}

tree::TerminalNode* QuilParser::FunctionContext::COS() {
  return getToken(QuilParser::COS, 0);
}

tree::TerminalNode* QuilParser::FunctionContext::SQRT() {
  return getToken(QuilParser::SQRT, 0);
}

tree::TerminalNode* QuilParser::FunctionContext::EXP() {
  return getToken(QuilParser::EXP, 0);
}

tree::TerminalNode* QuilParser::FunctionContext::CIS() {
  return getToken(QuilParser::CIS, 0);
}


size_t QuilParser::FunctionContext::getRuleIndex() const {
  return QuilParser::RuleFunction;
}

void QuilParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void QuilParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

QuilParser::FunctionContext* QuilParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 72, QuilParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QuilParser::SIN)
      | (1ULL << QuilParser::COS)
      | (1ULL << QuilParser::SQRT)
      | (1ULL << QuilParser::EXP)
      | (1ULL << QuilParser::CIS))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

QuilParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::SignContext::PLUS() {
  return getToken(QuilParser::PLUS, 0);
}

tree::TerminalNode* QuilParser::SignContext::MINUS() {
  return getToken(QuilParser::MINUS, 0);
}


size_t QuilParser::SignContext::getRuleIndex() const {
  return QuilParser::RuleSign;
}

void QuilParser::SignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSign(this);
}

void QuilParser::SignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSign(this);
}

QuilParser::SignContext* QuilParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 74, QuilParser::RuleSign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(359);
    _la = _input->LA(1);
    if (!(_la == QuilParser::PLUS

    || _la == QuilParser::MINUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

QuilParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QuilParser::RealNContext* QuilParser::NumberContext::realN() {
  return getRuleContext<QuilParser::RealNContext>(0);
}

QuilParser::ImaginaryNContext* QuilParser::NumberContext::imaginaryN() {
  return getRuleContext<QuilParser::ImaginaryNContext>(0);
}

tree::TerminalNode* QuilParser::NumberContext::I() {
  return getToken(QuilParser::I, 0);
}

tree::TerminalNode* QuilParser::NumberContext::PI() {
  return getToken(QuilParser::PI, 0);
}


size_t QuilParser::NumberContext::getRuleIndex() const {
  return QuilParser::RuleNumber;
}

void QuilParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void QuilParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}

QuilParser::NumberContext* QuilParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 76, QuilParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(365);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(361);
      realN();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(362);
      imaginaryN();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(363);
      match(QuilParser::I);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(364);
      match(QuilParser::PI);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImaginaryNContext ------------------------------------------------------------------

QuilParser::ImaginaryNContext::ImaginaryNContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QuilParser::RealNContext* QuilParser::ImaginaryNContext::realN() {
  return getRuleContext<QuilParser::RealNContext>(0);
}

tree::TerminalNode* QuilParser::ImaginaryNContext::I() {
  return getToken(QuilParser::I, 0);
}


size_t QuilParser::ImaginaryNContext::getRuleIndex() const {
  return QuilParser::RuleImaginaryN;
}

void QuilParser::ImaginaryNContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImaginaryN(this);
}

void QuilParser::ImaginaryNContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImaginaryN(this);
}

QuilParser::ImaginaryNContext* QuilParser::imaginaryN() {
  ImaginaryNContext *_localctx = _tracker.createInstance<ImaginaryNContext>(_ctx, getState());
  enterRule(_localctx, 78, QuilParser::RuleImaginaryN);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    realN();
    setState(368);
    match(QuilParser::I);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RealNContext ------------------------------------------------------------------

QuilParser::RealNContext::RealNContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QuilParser::RealNContext::FLOAT() {
  return getToken(QuilParser::FLOAT, 0);
}

tree::TerminalNode* QuilParser::RealNContext::INT() {
  return getToken(QuilParser::INT, 0);
}


size_t QuilParser::RealNContext::getRuleIndex() const {
  return QuilParser::RuleRealN;
}

void QuilParser::RealNContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealN(this);
}

void QuilParser::RealNContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QuilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealN(this);
}

QuilParser::RealNContext* QuilParser::realN() {
  RealNContext *_localctx = _tracker.createInstance<RealNContext>(_ctx, getState());
  enterRule(_localctx, 80, QuilParser::RuleRealN);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(370);
    _la = _input->LA(1);
    if (!(_la == QuilParser::INT

    || _la == QuilParser::FLOAT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool QuilParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 34: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool QuilParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> QuilParser::_decisionToDFA;
atn::PredictionContextCache QuilParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN QuilParser::_atn;
std::vector<uint16_t> QuilParser::_serializedATN;

std::vector<std::string> QuilParser::_ruleNames = {
  "quil", "allInstr", "instr", "gate", "name", "qubit", "param", "defGate", 
  "variable", "matrix", "matrixRow", "defCircuit", "qubitVariable", "circuitQubit", 
  "circuitGate", "circuitInstr", "circuit", "measure", "addr", "classicalBit", 
  "defLabel", "label", "halt", "jump", "jumpWhen", "jumpUnless", "resetState", 
  "wait", "classicalUnary", "classicalBinary", "nop", "include", "pragma", 
  "pragma_name", "expression", "segment", "function", "sign", "number", 
  "imaginaryN", "realN"
};

std::vector<std::string> QuilParser::_literalNames = {
  "", "'DEFGATE'", "'DEFCIRCUIT'", "'MEASURE'", "'LABEL'", "'HALT'", "'JUMP'", 
  "'JUMP-WHEN'", "'JUMP-UNLESS'", "'RESET'", "'WAIT'", "'NOP'", "'INCLUDE'", 
  "'PRAGMA'", "'FALSE'", "'TRUE'", "'NOT'", "'AND'", "'OR'", "'MOVE'", "'EXCHANGE'", 
  "'pi'", "'i'", "'sin'", "'cos'", "'sqrt'", "'exp'", "'cis'", "'+'", "'-'", 
  "'*'", "'/'", "'^'", "", "", "", "", "'.'", "','", "'('", "')'", "'['", 
  "']'", "':'", "'%'", "'@'", "'\"'", "'_'", "'    '", "", "", "' '"
};

std::vector<std::string> QuilParser::_symbolicNames = {
  "", "DEFGATE", "DEFCIRCUIT", "MEASURE", "LABEL", "HALT", "JUMP", "JUMPWHEN", 
  "JUMPUNLESS", "RESET", "WAIT", "NOP", "INCLUDE", "PRAGMA", "FALSE", "TRUE", 
  "NOT", "AND", "OR", "MOVE", "EXCHANGE", "PI", "I", "SIN", "COS", "SQRT", 
  "EXP", "CIS", "PLUS", "MINUS", "TIMES", "DIVIDE", "POWER", "IDENTIFIER", 
  "INT", "FLOAT", "STRING", "PERIOD", "COMMA", "LPAREN", "RPAREN", "LBRACKET", 
  "RBRACKET", "COLON", "PERCENTAGE", "AT", "QUOTE", "UNDERSCORE", "TAB", 
  "NEWLINE", "COMMENT", "SPACE", "INVALID"
};

dfa::Vocabulary QuilParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> QuilParser::_tokenNames;

QuilParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x36, 0x177, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x3, 0x2, 0x5, 0x2, 0x56, 
    0xa, 0x2, 0x3, 0x2, 0x6, 0x2, 0x59, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x5a, 
    0x3, 0x2, 0x7, 0x2, 0x5e, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x61, 0xb, 0x2, 
    0x3, 0x2, 0x7, 0x2, 0x64, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x67, 0xb, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x6e, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0x7e, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x7, 0x5, 0x85, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x88, 0xb, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x8c, 0xa, 0x5, 0x3, 0x5, 0x6, 0x5, 0x8f, 
    0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x90, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x7, 0x9, 0x9f, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xa2, 0xb, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xa6, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x7, 0xb, 0xb2, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xb5, 0xb, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 
    0xbd, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xc0, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xc8, 0xa, 0xd, 0xc, 
    0xd, 0xe, 0xd, 0xcb, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xcf, 0xa, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0xd2, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xd5, 0xb, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x5, 0xf, 0xdf, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xe6, 0xa, 0x10, 0xc, 0x10, 0xe, 
    0x10, 0xe9, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xed, 0xa, 0x10, 
    0x3, 0x10, 0x6, 0x10, 0xf0, 0xa, 0x10, 0xd, 0x10, 0xe, 0x10, 0xf1, 0x3, 
    0x11, 0x3, 0x11, 0x5, 0x11, 0xf6, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x7, 0x12, 0xfc, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xff, 
    0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x5, 0x13, 0x107, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x15, 0x6, 0x15, 0x10e, 0xa, 0x15, 0xd, 0x15, 0xe, 0x15, 
    0x10f, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 
    0x22, 0x138, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x13b, 0xb, 0x22, 0x3, 
    0x22, 0x5, 0x22, 0x13e, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x152, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x7, 0x24, 0x15d, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x160, 0xb, 
    0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x3, 0x28, 0x5, 0x28, 0x170, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x2, 0x3, 0x46, 0x2b, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
    0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 
    0x4e, 0x50, 0x52, 0x2, 0x9, 0x3, 0x2, 0x10, 0x12, 0x3, 0x2, 0x13, 0x16, 
    0x3, 0x2, 0x23, 0x24, 0x3, 0x2, 0x20, 0x21, 0x3, 0x2, 0x1e, 0x1f, 0x3, 
    0x2, 0x19, 0x1d, 0x3, 0x2, 0x24, 0x25, 0x2, 0x17f, 0x2, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x7f, 0x3, 0x2, 0x2, 0x2, 0xa, 0x92, 0x3, 0x2, 0x2, 0x2, 0xc, 0x94, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x96, 0x3, 0x2, 0x2, 0x2, 0x10, 0x98, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0xab, 0x3, 0x2, 0x2, 0x2, 0x14, 0xb3, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x18, 0xc1, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xda, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xde, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x20, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xfd, 0x3, 0x2, 0x2, 0x2, 0x24, 0x103, 0x3, 0x2, 0x2, 0x2, 0x26, 0x108, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x111, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x114, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x117, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x119, 0x3, 0x2, 0x2, 0x2, 0x32, 0x11c, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x120, 0x3, 0x2, 0x2, 0x2, 0x36, 0x124, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x126, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x12b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x40, 0x131, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x134, 0x3, 0x2, 0x2, 0x2, 0x44, 0x13f, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x151, 0x3, 0x2, 0x2, 0x2, 0x48, 0x161, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x167, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x169, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x50, 0x171, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x174, 0x3, 0x2, 0x2, 0x2, 0x54, 0x56, 0x5, 0x4, 0x3, 0x2, 0x55, 
    0x54, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x5f, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x59, 0x7, 0x33, 0x2, 0x2, 0x58, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 
    0x2, 0x5c, 0x5e, 0x5, 0x4, 0x3, 0x2, 0x5d, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x61, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x65, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 
    0x3, 0x2, 0x2, 0x2, 0x62, 0x64, 0x7, 0x33, 0x2, 0x2, 0x63, 0x62, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x67, 0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0x68, 0x3, 0x2, 0x2, 
    0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x7, 0x2, 0x2, 0x3, 
    0x69, 0x3, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6e, 0x5, 0x10, 0x9, 0x2, 0x6b, 
    0x6e, 0x5, 0x18, 0xd, 0x2, 0x6c, 0x6e, 0x5, 0x6, 0x4, 0x2, 0x6d, 0x6a, 
    0x3, 0x2, 0x2, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6c, 0x3, 
    0x2, 0x2, 0x2, 0x6e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x7e, 0x5, 0x8, 
    0x5, 0x2, 0x70, 0x7e, 0x5, 0x24, 0x13, 0x2, 0x71, 0x7e, 0x5, 0x2a, 0x16, 
    0x2, 0x72, 0x7e, 0x5, 0x2e, 0x18, 0x2, 0x73, 0x7e, 0x5, 0x30, 0x19, 
    0x2, 0x74, 0x7e, 0x5, 0x32, 0x1a, 0x2, 0x75, 0x7e, 0x5, 0x34, 0x1b, 
    0x2, 0x76, 0x7e, 0x5, 0x36, 0x1c, 0x2, 0x77, 0x7e, 0x5, 0x38, 0x1d, 
    0x2, 0x78, 0x7e, 0x5, 0x3a, 0x1e, 0x2, 0x79, 0x7e, 0x5, 0x3c, 0x1f, 
    0x2, 0x7a, 0x7e, 0x5, 0x3e, 0x20, 0x2, 0x7b, 0x7e, 0x5, 0x40, 0x21, 
    0x2, 0x7c, 0x7e, 0x5, 0x42, 0x22, 0x2, 0x7d, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x7d, 0x70, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x71, 0x3, 0x2, 0x2, 0x2, 0x7d, 
    0x72, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x73, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x74, 
    0x3, 0x2, 0x2, 0x2, 0x7d, 0x75, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x76, 0x3, 
    0x2, 0x2, 0x2, 0x7d, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x78, 0x3, 0x2, 
    0x2, 0x2, 0x7d, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7a, 0x3, 0x2, 0x2, 
    0x2, 0x7d, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7c, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x8b, 0x5, 0xa, 0x6, 0x2, 0x80, 
    0x81, 0x7, 0x29, 0x2, 0x2, 0x81, 0x86, 0x5, 0xe, 0x8, 0x2, 0x82, 0x83, 
    0x7, 0x28, 0x2, 0x2, 0x83, 0x85, 0x5, 0xe, 0x8, 0x2, 0x84, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x85, 0x88, 0x3, 0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 0x89, 0x3, 0x2, 0x2, 
    0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x2a, 0x2, 0x2, 
    0x8a, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x80, 0x3, 0x2, 0x2, 0x2, 0x8b, 
    0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8f, 
    0x5, 0xc, 0x7, 0x2, 0x8e, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x91, 0x9, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x23, 0x2, 
    0x2, 0x93, 0xb, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x7, 0x24, 0x2, 0x2, 
    0x95, 0xd, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x5, 0x46, 0x24, 0x2, 0x97, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x7, 0x3, 0x2, 0x2, 0x99, 0xa5, 
    0x5, 0xa, 0x6, 0x2, 0x9a, 0x9b, 0x7, 0x29, 0x2, 0x2, 0x9b, 0xa0, 0x5, 
    0x12, 0xa, 0x2, 0x9c, 0x9d, 0x7, 0x28, 0x2, 0x2, 0x9d, 0x9f, 0x5, 0x12, 
    0xa, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0xa1, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa3, 
    0xa4, 0x7, 0x2a, 0x2, 0x2, 0xa4, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa5, 0x9a, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x2d, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x33, 
    0x2, 0x2, 0xa9, 0xaa, 0x5, 0x14, 0xb, 0x2, 0xaa, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0xab, 0xac, 0x7, 0x2e, 0x2, 0x2, 0xac, 0xad, 0x7, 0x23, 0x2, 0x2, 
    0xad, 0x13, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x5, 0x16, 0xc, 0x2, 0xaf, 
    0xb0, 0x7, 0x33, 0x2, 0x2, 0xb0, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xae, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb1, 0x3, 
    0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x5, 0x16, 0xc, 
    0x2, 0xb7, 0x15, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0x32, 0x2, 0x2, 
    0xb9, 0xbe, 0x5, 0x46, 0x24, 0x2, 0xba, 0xbb, 0x7, 0x28, 0x2, 0x2, 0xbb, 
    0xbd, 0x5, 0x46, 0x24, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0x17, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 0x3, 0x2, 
    0x2, 0x2, 0xc1, 0xc2, 0x7, 0x4, 0x2, 0x2, 0xc2, 0xce, 0x5, 0xa, 0x6, 
    0x2, 0xc3, 0xc4, 0x7, 0x29, 0x2, 0x2, 0xc4, 0xc9, 0x5, 0x12, 0xa, 0x2, 
    0xc5, 0xc6, 0x7, 0x28, 0x2, 0x2, 0xc6, 0xc8, 0x5, 0x12, 0xa, 0x2, 0xc7, 
    0xc5, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 
    0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcc, 0x3, 
    0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x2a, 
    0x2, 0x2, 0xcd, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xce, 0xc3, 0x3, 0x2, 0x2, 
    0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0xd0, 0xd2, 0x5, 0x1a, 0xe, 0x2, 0xd1, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd2, 
    0xd5, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xd4, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd3, 0x3, 
    0x2, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x2d, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x33, 
    0x2, 0x2, 0xd8, 0xd9, 0x5, 0x22, 0x12, 0x2, 0xd9, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0xda, 0xdb, 0x7, 0x23, 0x2, 0x2, 0xdb, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xdf, 0x5, 0xc, 0x7, 0x2, 0xdd, 0xdf, 0x5, 0x1a, 0xe, 0x2, 0xde, 
    0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdf, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0xe0, 0xec, 0x5, 0xa, 0x6, 0x2, 0xe1, 0xe2, 0x7, 
    0x29, 0x2, 0x2, 0xe2, 0xe7, 0x5, 0xe, 0x8, 0x2, 0xe3, 0xe4, 0x7, 0x28, 
    0x2, 0x2, 0xe4, 0xe6, 0x5, 0xe, 0x8, 0x2, 0xe5, 0xe3, 0x3, 0x2, 0x2, 
    0x2, 0xe6, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 
    0xe7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe9, 
    0xe7, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x2a, 0x2, 0x2, 0xeb, 0xed, 
    0x3, 0x2, 0x2, 0x2, 0xec, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0xed, 0xef, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf0, 0x5, 0x1c, 
    0xf, 0x2, 0xef, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 
    0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 
    0xf2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf6, 0x5, 0x1e, 0x10, 0x2, 0xf4, 
    0xf6, 0x5, 0x6, 0x4, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf4, 
    0x3, 0x2, 0x2, 0x2, 0xf6, 0x21, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x7, 
    0x32, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x20, 0x11, 0x2, 0xf9, 0xfa, 0x7, 0x33, 
    0x2, 0x2, 0xfa, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf7, 0x3, 0x2, 0x2, 
    0x2, 0xfc, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 0x2, 
    0xfd, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x100, 0x3, 0x2, 0x2, 0x2, 0xff, 
    0xfd, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x7, 0x32, 0x2, 0x2, 0x101, 
    0x102, 0x5, 0x20, 0x11, 0x2, 0x102, 0x23, 0x3, 0x2, 0x2, 0x2, 0x103, 
    0x104, 0x7, 0x5, 0x2, 0x2, 0x104, 0x106, 0x5, 0xc, 0x7, 0x2, 0x105, 
    0x107, 0x5, 0x26, 0x14, 0x2, 0x106, 0x105, 0x3, 0x2, 0x2, 0x2, 0x106, 
    0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 0x25, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 
    0x7, 0x2b, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x28, 0x15, 0x2, 0x10a, 0x10b, 
    0x7, 0x2c, 0x2, 0x2, 0x10b, 0x27, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10e, 
    0x7, 0x24, 0x2, 0x2, 0x10d, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 
    0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 
    0x3, 0x2, 0x2, 0x2, 0x110, 0x29, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x7, 
    0x6, 0x2, 0x2, 0x112, 0x113, 0x5, 0x2c, 0x17, 0x2, 0x113, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x114, 0x115, 0x7, 0x2f, 0x2, 0x2, 0x115, 0x116, 0x7, 
    0x23, 0x2, 0x2, 0x116, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x7, 
    0x7, 0x2, 0x2, 0x118, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x7, 0x8, 
    0x2, 0x2, 0x11a, 0x11b, 0x5, 0x2c, 0x17, 0x2, 0x11b, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x11c, 0x11d, 0x7, 0x9, 0x2, 0x2, 0x11d, 0x11e, 0x5, 0x2c, 
    0x17, 0x2, 0x11e, 0x11f, 0x5, 0x26, 0x14, 0x2, 0x11f, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x120, 0x121, 0x7, 0xa, 0x2, 0x2, 0x121, 0x122, 0x5, 0x2c, 
    0x17, 0x2, 0x122, 0x123, 0x5, 0x26, 0x14, 0x2, 0x123, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x124, 0x125, 0x7, 0xb, 0x2, 0x2, 0x125, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x127, 0x7, 0xc, 0x2, 0x2, 0x127, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x128, 0x129, 0x9, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x5, 0x26, 0x14, 0x2, 
    0x12a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x9, 0x3, 0x2, 0x2, 0x12c, 
    0x12d, 0x5, 0x26, 0x14, 0x2, 0x12d, 0x12e, 0x5, 0x26, 0x14, 0x2, 0x12e, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x7, 0xd, 0x2, 0x2, 0x130, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x7, 0xe, 0x2, 0x2, 0x132, 0x133, 
    0x7, 0x26, 0x2, 0x2, 0x133, 0x41, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 
    0x7, 0xf, 0x2, 0x2, 0x135, 0x139, 0x7, 0x23, 0x2, 0x2, 0x136, 0x138, 
    0x5, 0x44, 0x23, 0x2, 0x137, 0x136, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13b, 
    0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 
    0x3, 0x2, 0x2, 0x2, 0x13a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 
    0x3, 0x2, 0x2, 0x2, 0x13c, 0x13e, 0x7, 0x26, 0x2, 0x2, 0x13d, 0x13c, 
    0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x43, 0x3, 
    0x2, 0x2, 0x2, 0x13f, 0x140, 0x9, 0x4, 0x2, 0x2, 0x140, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x142, 0x8, 0x24, 0x1, 0x2, 0x142, 0x143, 0x7, 0x29, 
    0x2, 0x2, 0x143, 0x144, 0x5, 0x46, 0x24, 0x2, 0x144, 0x145, 0x7, 0x2a, 
    0x2, 0x2, 0x145, 0x152, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x5, 0x4c, 
    0x27, 0x2, 0x147, 0x148, 0x5, 0x46, 0x24, 0xa, 0x148, 0x152, 0x3, 0x2, 
    0x2, 0x2, 0x149, 0x14a, 0x5, 0x4a, 0x26, 0x2, 0x14a, 0x14b, 0x7, 0x29, 
    0x2, 0x2, 0x14b, 0x14c, 0x5, 0x46, 0x24, 0x2, 0x14c, 0x14d, 0x7, 0x2a, 
    0x2, 0x2, 0x14d, 0x152, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x152, 0x5, 0x48, 
    0x25, 0x2, 0x14f, 0x152, 0x5, 0x4e, 0x28, 0x2, 0x150, 0x152, 0x5, 0x12, 
    0xa, 0x2, 0x151, 0x141, 0x3, 0x2, 0x2, 0x2, 0x151, 0x146, 0x3, 0x2, 
    0x2, 0x2, 0x151, 0x149, 0x3, 0x2, 0x2, 0x2, 0x151, 0x14e, 0x3, 0x2, 
    0x2, 0x2, 0x151, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x151, 0x150, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0xc, 0x9, 
    0x2, 0x2, 0x154, 0x155, 0x7, 0x22, 0x2, 0x2, 0x155, 0x15d, 0x5, 0x46, 
    0x24, 0x9, 0x156, 0x157, 0xc, 0x8, 0x2, 0x2, 0x157, 0x158, 0x9, 0x5, 
    0x2, 0x2, 0x158, 0x15d, 0x5, 0x46, 0x24, 0x9, 0x159, 0x15a, 0xc, 0x7, 
    0x2, 0x2, 0x15a, 0x15b, 0x9, 0x6, 0x2, 0x2, 0x15b, 0x15d, 0x5, 0x46, 
    0x24, 0x8, 0x15c, 0x153, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x15c, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x160, 0x3, 0x2, 
    0x2, 0x2, 0x15e, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x47, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15e, 0x3, 0x2, 0x2, 
    0x2, 0x161, 0x162, 0x7, 0x2b, 0x2, 0x2, 0x162, 0x163, 0x7, 0x24, 0x2, 
    0x2, 0x163, 0x164, 0x7, 0x1f, 0x2, 0x2, 0x164, 0x165, 0x7, 0x24, 0x2, 
    0x2, 0x165, 0x166, 0x7, 0x2c, 0x2, 0x2, 0x166, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x167, 0x168, 0x9, 0x7, 0x2, 0x2, 0x168, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x169, 0x16a, 0x9, 0x6, 0x2, 0x2, 0x16a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x16b, 
    0x170, 0x5, 0x52, 0x2a, 0x2, 0x16c, 0x170, 0x5, 0x50, 0x29, 0x2, 0x16d, 
    0x170, 0x7, 0x18, 0x2, 0x2, 0x16e, 0x170, 0x7, 0x17, 0x2, 0x2, 0x16f, 
    0x16b, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16f, 
    0x16d, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x170, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x5, 0x52, 0x2a, 0x2, 0x172, 
    0x173, 0x7, 0x18, 0x2, 0x2, 0x173, 0x51, 0x3, 0x2, 0x2, 0x2, 0x174, 
    0x175, 0x9, 0x8, 0x2, 0x2, 0x175, 0x53, 0x3, 0x2, 0x2, 0x2, 0x20, 0x55, 
    0x5a, 0x5f, 0x65, 0x6d, 0x7d, 0x86, 0x8b, 0x90, 0xa0, 0xa5, 0xb3, 0xbe, 
    0xc9, 0xce, 0xd3, 0xde, 0xe7, 0xec, 0xf1, 0xf5, 0xfd, 0x106, 0x10f, 
    0x139, 0x13d, 0x151, 0x15c, 0x15e, 0x16f, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

QuilParser::Initializer QuilParser::_init;
