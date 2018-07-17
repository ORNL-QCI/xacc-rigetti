
// Generated from Quil.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace quil {


class  QuilLexer : public antlr4::Lexer {
public:
  enum {
    DEFGATE = 1, DEFCIRCUIT = 2, MEASURE = 3, LABEL = 4, HALT = 5, JUMP = 6, 
    JUMPWHEN = 7, JUMPUNLESS = 8, RESET = 9, WAIT = 10, NOP = 11, INCLUDE = 12, 
    PRAGMA = 13, FALSE = 14, TRUE = 15, NOT = 16, AND = 17, OR = 18, MOVE = 19, 
    EXCHANGE = 20, PI = 21, I = 22, SIN = 23, COS = 24, SQRT = 25, EXP = 26, 
    CIS = 27, PLUS = 28, MINUS = 29, TIMES = 30, DIVIDE = 31, POWER = 32, 
    IDENTIFIER = 33, INT = 34, FLOAT = 35, STRING = 36, PERIOD = 37, COMMA = 38, 
    LPAREN = 39, RPAREN = 40, LBRACKET = 41, RBRACKET = 42, COLON = 43, 
    PERCENTAGE = 44, AT = 45, QUOTE = 46, UNDERSCORE = 47, TAB = 48, NEWLINE = 49, 
    COMMENT = 50, SPACE = 51, INVALID = 52
  };

  QuilLexer(antlr4::CharStream *input);
  ~QuilLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace quil
