"use strict";

function _toConsumableArray(arr) { return _arrayWithoutHoles(arr) || _iterableToArray(arr) || _nonIterableSpread(); }

function _nonIterableSpread() { throw new TypeError("Invalid attempt to spread non-iterable instance"); }

function _iterableToArray(iter) { if (Symbol.iterator in Object(iter) || Object.prototype.toString.call(iter) === "[object Arguments]") return Array.from(iter); }

function _arrayWithoutHoles(arr) { if (Array.isArray(arr)) { for (var i = 0, arr2 = new Array(arr.length); i < arr.length; i++) { arr2[i] = arr[i]; } return arr2; } }

function main(input) {
  var lines = input.split('\n');
  var S = lines[0];
  var nul = 1;
  var a = 0;
  var ab = 0;
  var abc = 0;
  var idx = 0;
  var _iteratorNormalCompletion = true;
  var _didIteratorError = false;
  var _iteratorError = undefined;

  try {
    for (var _iterator = S[Symbol.iterator](), _step; !(_iteratorNormalCompletion = (_step = _iterator.next()).done); _iteratorNormalCompletion = true) {
      var ch = _step.value;

      if (ch === 'A') {
        a = (a + nul) % P;
      } else if (ch === 'B') {
        ab = (ab + a) % P;
      } else if (ch === 'C') {
        abc = (abc + ab) % P;
      } else if (ch === '?') {
        abc = (abc * 3 + ab) % P;
        ab = (ab * 3 + a) % P;
        a = (a * 3 + nul) % P;
        nul = nul * 3 % P;
      }

      console.log(ch, a, ab, abc);
    }
  } catch (err) {
    _didIteratorError = true;
    _iteratorError = err;
  } finally {
    try {
      if (!_iteratorNormalCompletion && _iterator.return != null) {
        _iterator.return();
      }
    } finally {
      if (_didIteratorError) {
        throw _iteratorError;
      }
    }
  }

  console.log(abc);
}

var P = 1e9 + 7;
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

function splitNum(line) {
  return (Array.isArray(line) ? line : line.split(/\s+/)).map(function (n) {
    return parseInt(n);
  });
}
/**
 * Iterates over integers in [start, end).
 */


function* range(start, end) {
  for (var i = start; i < end; i++) {
    yield i;
  }
}
/**
 * Iterates over integers in [end, start) in desc order.
 */


function* rangeRev(start, end) {
  for (var i = start - 1; i >= end; i--) {
    yield i;
  }
}
/**
 * Runs a recursive function expressed as a generator function.
 */


function runRecursive(func) {
  // 最終結果を受け取るオブジェクトを用意
  var rootCaller = {
    lastReturnValue: null
  }; // 自前のコールスタックを用意

  var callStack = []; // 最初の関数呼び出しを追加

  for (var _len = arguments.length, args = new Array(_len > 1 ? _len - 1 : 0), _key = 1; _key < _len; _key++) {
    args[_key - 1] = arguments[_key];
  }

  callStack.push({
    iterator: func.apply(void 0, args),
    lastReturnValue: null,
    caller: rootCaller
  });

  while (callStack.length > 0) {
    var stackFrame = callStack[callStack.length - 1];
    var iterator = stackFrame.iterator,
        lastReturnValue = stackFrame.lastReturnValue,
        caller = stackFrame.caller; // 関数の実行を再開

    var _iterator$next = iterator.next(lastReturnValue),
        value = _iterator$next.value,
        done = _iterator$next.done;

    if (done) {
      // 関数がreturnしたので親に返り値を記録
      caller.lastReturnValue = value;
      callStack.pop();
    } else {
      // 関数がyieldした（valueは再帰呼び出しの引数リスト）
      callStack.push({
        iterator: func.apply(void 0, _toConsumableArray(value)),
        lastReturnValue: null,
        caller: stackFrame
      });
    }
  }

  return rootCaller.lastReturnValue;
}
